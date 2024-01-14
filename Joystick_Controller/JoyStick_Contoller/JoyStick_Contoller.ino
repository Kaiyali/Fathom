#include <LiquidCrystal.h>
#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A5 // Arduino pin connected to VRX pin

//buttons
#define BTN_BTM_LEFT  5
#define BTN_CTN_LEFT  4
#define BTN_TOP_LEFT  3

// #define BTN_BTM_RIGHT  0
// #define BTN_CTN_RIGHT  1
// #define BTN_TOP_RIGHT  2



int rawXValue = 0; // To store value of the X axis
int rawYValue = 0; // To store value of the X axis





void setup() {
  Serial.begin(9600);
  pinMode(BTN_BTM_LEFT, INPUT_PULLUP);
}

void loop() {
  // read analog X and Y analog values
  rawXValue = analogRead(VRX_PIN);
  rawYValue = analogRead(VRY_PIN);

  int xValue = map(rawXValue, 0, 1023, -100, 100); // Maps the raw analog input value to a range of -100 to 100
  int yValue = map(rawYValue, 0, 1023, -100, 100); // Maps the raw analog input value to a range of -100 to 100

  byte Status_BTN_BTM_LEFT = digitalRead(BTN_BTM_LEFT);
  byte Status_BTN_CTN_LEFT = digitalRead(BTN_CTN_LEFT);
  byte Status_BTN_TOP_LEFT = digitalRead(BTN_TOP_LEFT);
  // byte Status_BTN_BTM_RIGHT = digitalRead(BTN_BTM_RIGHT);
  // byte Status_BTN_CTN_RIGHT = digitalRead(BTN_CTN_RIGHT);
  // byte Status_BTN_TOP_RIGHT = digitalRead(BTN_TOP_RIGHT);

  if(xValue >= 20){
    Serial.println("it is turning left");
    delay(1000);
  }
  if(xValue <= -20){
    Serial.println("it is turning right");
    delay(1000);
  }
  
  if(yValue >= 20){
    Serial.println("it is turning backward");
    delay(1000);
  }
  if(yValue <= -20 ){
    Serial.println("it is turning forward");
    delay(1000);
  } 


  // if (Status_BTN_TOP_LEFT == LOW) {
  //     Serial.print("Status_BTN_BTM_LEFT: ");
  //     delay(1000);
  // } else {
  //     Serial.println("Button is not pressed");
  // }
 

}

