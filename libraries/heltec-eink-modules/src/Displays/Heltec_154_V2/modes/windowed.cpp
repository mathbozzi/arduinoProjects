#include "Displays/Heltec_154_V2/Heltec_154_V2.h"

//Methods that run depending on the selected screen mode


bool Heltec_154_V2::calculating_Windowed() {

	//Beginning of first loop
	//===============
	if (page_cursor == 0) {

		// //Calculate rotated window locations
		// switch (rotation) {
		// 	case 0:
		// 		winrot_top = window_top;
		// 		winrot_right = window_right;
		// 		winrot_bottom = window_bottom;
		// 		winrot_left = window_left;
		// 		break;

		// 	case 1:
		// 		winrot_top = window_left;
		// 		winrot_right = panel_width - window_top;
		// 		winrot_bottom = window_right;
		// 		winrot_left = panel_width - window_bottom;
		// 		break;

		// 	case 2:
		// 		winrot_top = panel_height - window_bottom;
		// 		winrot_right = panel_width - window_left;
		// 		winrot_bottom = panel_height - window_top;
		// 		winrot_left = panel_width - window_right;
		// 		break;
			
		// 	case 3:
		// 		winrot_top = panel_height - window_right;
		// 		winrot_right = window_bottom;
		// 		winrot_bottom = panel_height - window_left;
		// 		winrot_left = window_top;
		// }

		//Limit window to panel 
		if (window_left < 0) 					window_left = 0;
		if (window_top < 0)						window_top = 0;
		if (rotation % 2) {	//Landscape
			if (window_right > drawing_height)		window_right = drawing_height;
			if (window_bottom > drawing_width)		window_bottom = drawing_width;
		}
		else {	//Portrait
			if (window_right > drawing_width)		window_right = drawing_width;
			if (window_bottom > drawing_height)		window_bottom = drawing_height;
		}

		//Calculate rotated window locations
		uint16_t target_byte;
		switch (rotation) {
			case 0:
				winrot_left = window_left;
				winrot_left = winrot_left - (winrot_left % 8);	//Expand box on left to fit contents

				winrot_right = winrot_left;
				while(winrot_right < window_right) winrot_right += 8;	//Iterate until box includes the byte where our far-left bit lives

				winrot_top = window_top;
				winrot_bottom = window_bottom + 1;
				break;

			case 1:
				winrot_left = drawing_width - window_bottom - 1;
				winrot_left = winrot_left - (winrot_left % 8);	//Expand box on left to fit contents

				winrot_right = winrot_left;
				while(winrot_right < drawing_width - window_top) winrot_right += 8;	//Iterate until box includes the byte where our far-left bit lives

				winrot_top = window_left;
				winrot_bottom = window_right + 1;
				break;

			case 2:	
				winrot_right = drawing_width - window_left;
				winrot_right = winrot_right - (winrot_right % 8);
				while(winrot_right < drawing_width - window_left) winrot_right += 8;	//Iterate until box includes the byte for the far-right

				winrot_left = winrot_right;
				target_byte = (drawing_width - window_right - 1) - ((drawing_width - window_right - 1) % 8);
				while(winrot_left > target_byte) winrot_left -= 8;	//Iterate until box includes the byte where our far-left bit lives

				winrot_bottom = drawing_height - window_top;
				winrot_top = drawing_height - window_bottom - 1;

				break;

			
			case 3:
				winrot_left = window_top;
				winrot_left = winrot_left - (winrot_left % 8);	//Expand box on left to fit contents

				winrot_right = winrot_left;
				while(winrot_right < window_bottom) winrot_right += 8;	//Iterate until box includes the byte where our far-left bit lives

				winrot_top = (drawing_height - window_right) - 1;
				winrot_bottom = (drawing_height - window_left);
				break;
		}

		grabPageMemory();		//This will grab slightly too much memory, but not a priority right now. TODO: fix eventually
		clearPage(default_color);
		wake();					//Get the panel ready to receive the spi data

		page_top = winrot_top;	//We're now translating the window in drawPixel()
		page_bottom = winrot_top + page_profile.height;
		pagefile_length = (page_bottom - page_top) * ((winrot_right - winrot_left) / 8);
	}

	//End of each loop
	//===============
	else {
		//Check if the last page contained any part of the window
		if (!(winrot_bottom < page_top || winrot_top > page_bottom))
			writePage_Windowed();	//Send off the old page

		//Calculate memory locations for the new page
		page_top += page_profile.height;
		page_bottom = min(page_top + page_profile.height, winrot_bottom);
		pagefile_length = (page_bottom - page_top) * ((winrot_right - winrot_left) / 8);
		clearPage(default_color);
	}

	//Check whether loop should continue
	//=============
	if (page_top > winrot_bottom) {
		page_cursor = 0; //Reset for next time
		//update();		//We will make the user call the update manually
		freePageMemory();
		return false;	//We're done
	}
	else {
		page_cursor++;
		return true;	//Keep looping
	}
}

void Heltec_154_V2::drawPixel_Windowed(int16_t x, int16_t y, uint16_t color) {

	//Rotate the pixel
	int16_t x1, y1;
	switch(rotation) {
		case 0:			//No rotation
			x1=x;
			y1=y;
			break;
		case 1:			//90deg clockwise
			x1 = (panel_height - y - 1);
			y1 = x;
			break;
		case 2:			//180deg
			x1 = (panel_width - 1) - x;
			y1 = (panel_height - 1) - y;
			break;
		case 3:			//270deg clockwise
			x1 = y;
			y1 = (panel_height - 1) - x;
			break;
	}
	x = x1;
	y = y1;

	//Handle flip
	if (imgflip & FlipList::HORIZONTAL) {
		if (rotation % 2)	//If landscape
			y = (drawing_height - 1) - y;
		else					//If portrait
			x = (drawing_width - 1) - x;
	}
	if (imgflip & FlipList::VERTICAL) {
		if (rotation % 2)	//If landscape
			x = (drawing_width - 1) - x;
		else					//If portrait
			y = (drawing_height - 1) - y;
	}

	//Check if pixel falls in our page
	if(x >= winrot_left && y >= page_top && y <= page_bottom && x <= winrot_right - 1) {

		//Calculate a memory location for our pixel
		//A whole lot of emperically derived "inverting" went on here
		//The y values of the pixels in each page are inverted, but not the pages themselves
		//The bit order of the x pixels is inverted, but not the order of the pixels themselves
		//To top it off, one final inversion is needed in writePage(), but all the nonsense seems to balance out eventually
		//(This is probably all my fault)

		uint16_t memory_location;
		
		memory_location = (y - page_top) * ((winrot_right - winrot_left) / 8);
		memory_location += ((x - winrot_left) / 8);		
		uint8_t bit_location = x % 8;	//Find the location of the bit in which the value will be stored
		bit_location = (7 - bit_location);	//For some reason, the screen wants the bit order flipped. MSB vs LSB?

		//Insert the correct color values into the appropriate location
		uint8_t bitmask = ~(1 << bit_location);
		page_black[memory_location] &= bitmask;
		page_black[memory_location] |= (color & colors.WHITE) << bit_location;
	}
}

void Heltec_154_V2::writePage_Windowed() {
	//Calculate rotate x start and stop values (y is already done via paging)

	int16_t sx, sy, ex, ey;

	sx = winrot_left / 8;
	sy = page_top;
	ex = (winrot_right / 8) - 1;
	ey = page_bottom;

	//"Data entry mode??"	-- new undocumented command from heltec sdk
	sendCommand(0x11); //data entry mode
  	sendData(0x03);

	//Inform the panel hardware of our chosen memory location
	sendCommand(0x44);	//Memory X start - end
	sendData(sx);
	sendData(ex);
	sendCommand(0x45);	//Memory Y start - end
	sendData(sy);
	sendData(0);										//Bit 8 - not required, max y is 250
	sendData(ey);
	sendData(0);										//Bit 8 - not required, max y is 250
	sendCommand(0x4E);	//Memory cursor X
	sendData(sx);
	sendCommand(0x4F);	//Memory cursor y
	sendData(sy);
	sendData(0);										//Bit 8 - not required, max y is 250

	//Now we can send over our image data

	sendCommand(0x24);   //write memory for black(0)/white (1)
	for (uint16_t i = 0; i < pagefile_length; i++) {
		sendData(page_black[i]);
	}

    sendCommand(0x26);   //write memory for black(0)/white (1)
	for (uint16_t i = 0; i < pagefile_length; i++) {
		sendData(~page_black[i]);
	}

	wait();
	//Nothing happens now until update() is called
}