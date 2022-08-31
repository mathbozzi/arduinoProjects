//---------------------------------------------------------------------
//Which display are you using?  (uncomment one)

//#define   USING_Heltec_154_V2
//#define   USING_Heltec_213Red_V2
//#define   USING_Heltec_290_V2


//Where is your display connected?

#define DC_PIN 8
#define CS_PIN 10
#define BUSY_PIN 7


//(Example automatically picks the correct class and sample image)
#if     defined USING_Heltec_154_V2
            #define     PANEL_CLASS     Heltec_154_V2    
#elif   defined USING_Heltec_213Red_V2
            #define     PANEL_CLASS     Heltec_213Red_V2    
#elif   defined USING_Heltec_290_V2
            #define     PANEL_CLASS     Heltec_290_V2    
#endif
//----------------------------------------------------------------------


//DEMO: Sprites
//=================================
  //XBitmaps are well suited for storing graphic elements that can be prerendered and then placed where neeeded

#include "heltec-eink-modules.h"

//Here we are including a small image of a ball
#include "ball.h"

PANEL_CLASS display(DC_PIN, CS_PIN, BUSY_PIN);

void setup() {
  display.begin();
  display.setRotation(display.orientation.PINS_RIGHT);

  //Useful drawing aides
  static uint16_t TOP = 0;
  static uint16_t BOTTOM = display.bounds.full.bottom();
  static uint16_t LEFT = 0;
  static uint16_t RIGHT = display.bounds.full.bottom();
  static uint16_t CENTER_X = display.bounds.full.centerX();
  static uint16_t CENTER_Y = display.bounds.full.centerY();

  static uint16_t ball_offset = 53;

  while( display.calculating() ) {
    //First draw a ball in the background, top centre
    display.drawXBitmap(CENTER_X - (ball_width / 2), CENTER_Y - (ball_width / 2) - ball_offset, ball_bits, ball_width, ball_height, display.colors.BLACK);

    //ball in the bottom left
    //Note that the XBitmap only specifies location of one color. This allows transparency
    display.drawXBitmap(CENTER_X - (ball_width / 2) - ball_offset, CENTER_Y - (ball_width / 2), ball_bits, ball_width, ball_height, display.colors.BLACK);
    
    //Another ball in the bottom right
    //To prevent a transparency effect, you will need either a second xbitmap, or to write a background of white pixels underneath 
    display.fillCircle(CENTER_X + ball_offset, CENTER_Y, ball_width / 2, display.colors.WHITE);
    display.drawXBitmap(CENTER_X - (ball_width / 2) + ball_offset, CENTER_Y - (ball_width / 2), ball_bits, ball_width, ball_height, display.colors.BLACK);
  }

  display.update();   //The display will only begin to change once update() is called

}

void loop() {}
