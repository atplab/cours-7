#include <Arduino.h>
#include <FastLED.h>
#include <M5_PbHub.h>
#include <MicroOscSlip.h>
M5_PbHub myPbHub;


#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_LUMIERE 27
#define BROCHE_ATOM_BOUTON 39
#define KEY_CHANNEL 0
//CRGB keyPixel;
CRGB monPixel;
MicroOscSlip<128> monOsc(&Serial);
void setup()
{
  pinMode(BROCHE_ATOM_FIL_BLANC, INPUT_PULLUP);
  Serial.begin(115200);

  Wire.begin();
  myPbHub.begin();


}

void loop()
{

  int maLectureKey = myPbHub.digitalRead( KEY_CHANNEL );
  
  monOsc.sendInt( "/bouton" , maLectureKey );

  delay(100);

  //int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);

  
}
