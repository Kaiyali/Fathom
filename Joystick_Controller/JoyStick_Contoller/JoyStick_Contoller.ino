#include <LiquidCrystal.h>
#define VRX_PIN  A1 // Arduino pin connected to VRX pin
#define VRY_PIN  A0 // Arduino pin connected to VRX pin

int rawXValue = 0; // To store value of the X axis
int rawYValue = 0; // To store value of the X axis



void setup() {
  Serial.begin(9600) ;
}

void loop() {
  // read analog X and Y analog values
  rawXValue = analogRead(VRY_PIN);
  rawYValue = analogRead(VRX_PIN);

  int xValue = map(rawXValue, 0, 1023, -100, 100); // Maps the raw analog input value to a range of -100 to 100
  int yValue = map(rawYValue, 0, 1023, -100, 100); // Maps the raw analog input value to a range of -100 to 100



  if(xValue >= 20){
    Serial.println("it is turning left");
  }
  if(xValue <= -20){
    Serial.println("it is turning right");
  }
  
  if(yValue >= 20){
    Serial.println("it is turning backward");
  }
  if(yValue <= -20 ){
    Serial.println("it is turning forward");
  }

  // if(abs(xValue) <= 20 && abs(yValue) <= 20 ){
  //   Serial.println("it is in the center");
  // }
}


