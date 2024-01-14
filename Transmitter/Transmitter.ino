//Transmitter
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A5 // Arduino pin connected to VRX pin

RF24 radio(9, 8); // CE, CSN
const byte address[10] = "FATHOMADD";

int rawXValue = 0; // To store value of the X axis
int rawYValue = 0; // To store value of the Y axis
const char txtLeft[] = "LEFT";
const char txtRight[] = "RIGHT";
const char txtBack[] = "BWD";
const char txtFront[] = "FWD";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
}

void loop()
{
  rawXValue = analogRead(VRY_PIN);
  rawYValue = analogRead(VRX_PIN);
  
  int xValue = map(rawXValue, 0, 1023, -100, 100); // Maps the raw analog input value to a range of -100 to 100
  int yValue = map(rawYValue, 0, 1023, -100, 100); // Maps the raw analog input value to a range of -100 to 100

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

  delay(1000);
}
