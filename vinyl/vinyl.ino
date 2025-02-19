#include <Audio.h>
#include "Vinyl.h"

Vinyl vinyl;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(vinyl,0,out,0);
AudioConnection patchCord1(vinyl,1,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.1);
}

void loop() {
  vinyl.setParamValue("freq",random(50,1000));
  delay(50);
}