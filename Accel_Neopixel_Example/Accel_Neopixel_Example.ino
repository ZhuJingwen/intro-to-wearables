#include <Wire.h>
#include <Adafruit_LSM303.h>



#include <Adafruit_NeoPixel.h>
#define PIN 8

Adafruit_LSM303 lsm;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  Serial.begin(9600);
  
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM303. Check your wiring!");
    while (1);
  }

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() 
{
  lsm.read();
  int x = (int)lsm.accelData.x;
  int r  = map(x, -1024, 1024, 0, 255);
  Serial.println(r);
  strip.setPixelColor(0, r, 0,100);
  strip.show();
  delay(100);
}
