#include <Wire.h>
#include <Adafruit_LSM303.h>
Adafruit_LSM303 lsm;

int ledPin = 10; //connect a LED sequin to D10

void setup() 
{
  Serial.begin(9600);
  
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
    while (1);
  }
pinMode(ledPin, OUTPUT);
}

void loop() 
{
  lsm.read();
  int x = (int)lsm.accelData.x;
  int brightness  = map(x, -1024, 1024, 0, 255);
  analogWrite(ledPin, brightness);
  Serial.println(brightness);
  delay(100);
}
