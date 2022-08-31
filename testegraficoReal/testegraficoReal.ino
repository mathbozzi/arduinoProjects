#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);
#define sensor A0
unsigned long ult = 0;

String comando;

void setup() {

  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  
  if(bluetooth.available()>0){
    char re = bluetooth.read();
    switch(re){
      case 'J':
        start();
      break;
    }
  }
}

void start(){
  while(1){
    
     unsigned long now = millis();
     if((now - ult) > 300){
        ult = now;
        float p = floatMap(analogRead(sensor),0,1023,0,5);
        p = p*25;
        bluetooth.print(p,2);
        Serial.println(p);
        if(p >= 200){
          bluetooth.print("K");
          delay(20);
        }
        //bluetooth.print(floatMap(analogRead(sensor),0,1023,0,5),2);
        if(bluetooth.available()>0){
          if(bluetooth.read()=='Q'){
            return;
          }            
        }   
     }
       
  }
}

float floatMap(float x, float inMin,float inMax, float outMin, float outMax){
  return (x-inMin)*(outMax-outMin)/(inMax-inMin)+outMax;
}
