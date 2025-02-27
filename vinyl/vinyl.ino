#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <USBHost_t36.h>

#include "Vinyl.h"
#include <cmath>

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11
#define SDCARD_SCK_PIN 13

Vinyl vinyl;
AudioOutputI2S out;
AudioPlaySdWav audioSD;
AudioControlSGTL5000 audioShield;
AudioMixer4 mix;

AudioConnection patchCord0(audioSD, 0, vinyl, 0);
AudioConnection patchCord1(vinyl, 0, mix, 0);
AudioConnection patchCord2(mix, 0, out, 0); 
AudioConnection patchCord3(mix, 0, out, 1); 

char receivedTitle[20] = "YINTIAN.WAV";  // Stocke les caractères du titre (max 7 + '\0')
int titleIndex = 0;
bool titleReceived = false;
bool isPlaying = true;

void setup() {
  Serial.begin(9600);

  usbMIDI.begin();
  usbMIDI.setHandleControlChange(handleControlChange);

  audioShield.enable();
  audioShield.volume(0.5);
  AudioMemory(20);
  mix.gain(0, 1);
  mix.gain(1, 0);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);

  Serial.println("Checking SD Card...");
  if (!SD.begin(SDCARD_CS_PIN)) {
    Serial.println("SD Card initialization failed!");
    while (1) delay(500);
  }
  Serial.println("SD Card OK.");
}

void loop() {
  usbMIDI.read();  // Vérifie les messages MIDI entrants

  // Si un titre a été complètement reçu, on le charge
  if (titleReceived) {
    playTitle();
    titleReceived = false;
  }

  // Gérer la lecture automatique si elle est activée
  if (isPlaying && !audioSD.isPlaying()) {
    audioSD.play(receivedTitle);
    Serial.print("Lecture automatique : ");
    Serial.println(receivedTitle);
  }

  delay(100);
}

void handleControlChange(byte channel, byte controller, byte value) {
  float newValue = value / 127.0;
  
  switch (controller) {
    case 7:  // Volume général
        audioShield.volume(newValue);
        Serial.print("Volume réglé à : ");
        Serial.println(newValue);
      break;

    case 8:  // Bruit blanc
      vinyl.setParamValue("white_noise", newValue);
      Serial.print("Bruit blanc: ");
      Serial.println(newValue);
      break;

    case 9:  // Son de scratch
      vinyl.setParamValue("scratch_sound", newValue);
      Serial.print("Scratch: ");
      Serial.println(newValue);
      break;

    case 10:  // Son de poussière
      vinyl.setParamValue("dust_sound", newValue);
      Serial.print("Poussière: ");
      Serial.println(newValue);
      break;

    case 11:  // Ronflement
      vinyl.setParamValue("rumble", newValue);
      Serial.print("Ronflement: ");
      Serial.println(newValue);
      break;

    case 12:  // Bruit moteur
      vinyl.setParamValue("motor_noise", newValue);
      Serial.print("Bruit moteur: ");
      Serial.println(newValue);
      break;

    case 14:  // Play/Pause
      if (value == 127) {  
        if (!audioSD.isPlaying()) {
          isPlaying = true;
          Serial.println("Lecture : PLAY");
          audioSD.play(receivedTitle);
        } else {
          Serial.println("Déjà en lecture.");
        }
      } else {  
        isPlaying = false;
        Serial.println("Lecture : PAUSE");
        audioSD.stop();
      }
      break;


    case 20 ... 30:  // Réception du titre en ASCII (max 7 caractères)
      receivedTitle[controller - 20] = (char)value;
      if (controller == 26) {  // Fin du titre reçu
        receivedTitle[19] = '\0';  // Terminer la chaîne proprement
        titleReceived = true;
        Serial.print("Titre reçu : ");
        Serial.println(receivedTitle);
      }
      break;

    default:
      Serial.print("MIDI CC non géré: ");
      Serial.println(controller);
      break;
  }
}

void playTitle() {
  Serial.print("Lecture du fichier : ");
  Serial.println(receivedTitle);

  if (SD.exists(receivedTitle)) {
    audioSD.play(receivedTitle);
    isPlaying = true;
  } else {
    Serial.println("Fichier introuvable sur la carte SD !");
  }
}



