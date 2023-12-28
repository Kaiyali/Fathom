//Transmitter
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define VRX_PIN  A0 // Arduino pin connected to VRX pin
#define VRY_PIN  A1 // Arduino pin connected to VRX pin

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

  if (xValue >= 20)
  {
    radio.write(txtLeft, sizeof(txtLeft));
    Serial.println(txtLeft);
    
  }
  if (xValue <= -20)
  {
    radio.write(txtRight, sizeof(txtRight));
    Serial.println(txtRight);
  }

  if (yValue >= 20)
  {
    radio.write(txtBack, sizeof(txtBack));
    Serial.println(txtBack);
  }
  if (yValue <= -20)
  {
    Serial.println(txtFront);
    radio.write(txtFront, sizeof(txtFront));
  }

  delay(1000);
}
