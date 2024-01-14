#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address [10] = "FATHOMADD";

int KILL = 7;
int FWD = 6; 
int BWD = 5;


void setup()
{
  
  pinMode(FWD, OUTPUT);
  pinMode(KILL, OUTPUT);
  pinMode(BWD, OUTPUT);

  Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}

void loop(){

  //Read the data if available in buffer
  char text[32] = {0};
  if (radio.available())
  {
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }

  if (strcmp(text, "FWD") == 0) {
    digitalWrite(KILL, HIGH);
    digitalWrite(FWD, HIGH);
    Serial.println("Moving Forward");
  }
  if (strcmp(text, "BWD") == 0) {
    Serial.println("Moving Forward");
  }
}