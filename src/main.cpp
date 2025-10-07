#include <Arduino.h>
#include <FastLED.h>
#include <M5_PbHub.h>
M5_PbHub myPbHub;


#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_LUMIERE 27
#define BROCHE_ATOM_BOUTON 39
#define KEY_CHANNEL 0
//CRGB keyPixel;
CRGB monPixel;

void setup()
{
  // Initialiser FastLED pour contrôler le pixel RGB du M5Stack Key Unit
  //FastLED.addLeds<WS2812, BROCHE_ATOM_FIL_JAUNE, GRB>(&keyPixel, 1);
  //pinMode(BROCHE_ATOM_FIL_BLANC, INPUT_PULLUP);
  FastLED.addLeds<WS2812, BROCHE_ATOM_LUMIERE, GRB>(&monPixel, 1);
  pinMode(BROCHE_ATOM_BOUTON, INPUT);

  Wire.begin();
  myPbHub.begin();
  myPbHub.setPixelCount( KEY_CHANNEL ,  1 );

}

void loop()
{

  int maLectureKey = myPbHub.digitalRead( KEY_CHANNEL );
  


  //int maLectureKey = digitalRead(BROCHE_ATOM_FIL_BLANC);

  if (maLectureKey == 0)
  {
    myPbHub.setPixelColor(KEY_CHANNEL, 0, 127, 255, 0);
    //keyPixel = CRGB(0, 255, 255);
    
  }

  else
  {
    myPbHub.setPixelColor(KEY_CHANNEL, 0, 0, 0, 0);
    //keyPixel = CRGB(255, 255, 0);
    
  }

  int maLectureLumiere = digitalRead(BROCHE_ATOM_BOUTON);

  if (maLectureLumiere == 0)
  {
    
    monPixel = CRGB(255, 255, 255);
  }else
  {
    
    monPixel = CRGB(0, 0, 0);
  }
  FastLED.show();
  delay(20);
}
