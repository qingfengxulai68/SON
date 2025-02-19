#include "MyDsp.h"
#include "MyDsp.cpp"
#include <Arduino.h>

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  myDsp.setFreq(500); // hz
  delay(300);
}
