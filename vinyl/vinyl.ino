// #include <Audio.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

// #include "Vinyl.h"
// #include <cmath>

// #define SDCARD_CS_PIN 10
// #define SDCARD_MOSI_PIN  11
// #define SDCARD_SCK_PIN   13
// #define PLAY_BUTTON_PIN 2

// Vinyl vinyl;
// AudioOutputI2S out;
// AudioPlaySdWav audioSD;
// AudioControlSGTL5000 audioShield;
// AudioMixer4 mix;

// AudioConnection patchCord0(vinyl, 0, mix, 0);
// AudioConnection patchCord1(audioSD, 0, mix, 1);
// AudioConnection patchCord2;
// AudioConnection patchCord3;

// void setup() {

//   audioShield.enable();
//   audioShield.volume(2);
//   AudioMemory(4);
//   pinMode(PLAY_BUTTON_PIN, INPUT_PULLUP);
//   mix.gain(0, 5);
//   mix.gain(1, 0.15);

//   SPI.setMOSI(SDCARD_MOSI_PIN);
//   SPI.setSCK(SDCARD_SCK_PIN);
//   if (!(SD.begin(SDCARD_CS_PIN))) {
//     while (1) {
//       delay(500);
//     }
//   }
// }

// void loop() {
//   int knobValue = analogRead(A4);
//   int playButtonState = digitalRead(PLAY_BUTTON_PIN);
//   float gain = map(knobValue, 0, 1023, 0, 7);
//   mix.gain(0, gain);

//   static float previousGainValue = -1.0;
//   float gainValue = knobValue / 102.3;
//   if (fabs(gainValue - previousGainValue) > 0.1) {
//     usbMIDI.sendControlChange(7, gainValue * 127 / 7, 1); // CC 7: Volume
//     previousGainValue = gainValue;
//   }

//   if (playButtonState == LOW && audioSD.isPlaying() == false) {
//     usbMIDI.sendNoteOn(60, 127, 1); // MIDI Note On
//     delay(800);
//     audioSD.play("yintian.WAV");
//     patchCord2.connect(mix, 0, out, 0);
//     patchCord3.connect(mix, 0, out, 1);
//     delay(500);
//   } else if (playButtonState == LOW && audioSD.isPlaying() == true) {
//     usbMIDI.sendNoteOff(60, 0, 1); // MIDI Note Off
//     delay(100);
//     audioSD.stop();
//     patchCord2.disconnect();
//     patchCord3.disconnect();
//     delay(500);
//   }

//   usbMIDI.read(); 
//   delay(100);
// }





//button功能删除后 && potentiometre删除后
// #include <Audio.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

// #include "Vinyl.h"
// #include <cmath>

// #define SDCARD_CS_PIN 10
// #define SDCARD_MOSI_PIN  11
// #define SDCARD_SCK_PIN   13

// Vinyl vinyl;
// AudioOutputI2S out;
// AudioPlaySdWav audioSD;
// AudioControlSGTL5000 audioShield;
// AudioMixer4 mix;

// AudioConnection patchCord0(vinyl, 0, mix, 0);
// AudioConnection patchCord1(audioSD, 0, mix, 1);
// AudioConnection patchCord2;
// AudioConnection patchCord3;

// void setup() {
//   audioShield.enable();
//   audioShield.volume(2); // 设置音频盾的音量
//   AudioMemory(4); // 分配音频内存
//   mix.gain(0, 5);  // 设置输入 0 的增益
//   mix.gain(1, 0.15); // 设置输入 1（SD卡音频）的增益

//   SPI.setMOSI(SDCARD_MOSI_PIN);
//   SPI.setSCK(SDCARD_SCK_PIN);
//   if (!(SD.begin(SDCARD_CS_PIN))) {
//     while (1) {
//       delay(500);
//     }
//   }

//   // 播放音乐
//   audioSD.play("YINTIAN.WAV");
//   patchCord2.connect(mix, 0, out, 0);  // 将 mix 信号连接到输出
//   patchCord3.connect(mix, 0, out, 1);  // 将 mix 信号连接到输出
// }

// void loop() {
//   // 🔥 移除了旋钮输入控制代码

//   // 如果音乐播放结束，自动重新播放
//   if (!audioSD.isPlaying()) {
//     audioSD.play("YINTIAN.WAV");
//   }

//   delay(100); // 延迟，避免过多重复执行
// }



// 删除vinyl相关后：成功播放音乐

// #include <Audio.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

// #define SDCARD_CS_PIN 10
// #define SDCARD_MOSI_PIN  11
// #define SDCARD_SCK_PIN   13

// AudioOutputI2S out;
// AudioPlaySdWav audioSD;
// AudioControlSGTL5000 audioShield;
// AudioMixer4 mix;

// AudioConnection patchCord0(audioSD, 0, mix, 0);
// AudioConnection patchCord1(mix, 0, out, 0);
// AudioConnection patchCord2(mix, 0, out, 1);

// void setup() {
//   Serial.begin(9600);

//   audioShield.enable();
//   audioShield.volume(2);
//   AudioMemory(4);
//   mix.gain(0, 0.5);

//   SPI.setMOSI(SDCARD_MOSI_PIN);
//   SPI.setSCK(SDCARD_SCK_PIN);
  
//   Serial.println("Checking SD Card...");
//   if (!SD.begin(SDCARD_CS_PIN)) {
//     Serial.println("SD Card initialization failed!");
//     while (1) {
//       delay(500);
//     }
//   }
//   Serial.println("SD Card OK.");

//   if (!SD.exists("YINTIAN.WAV")) {
//     Serial.println("ERROR: YINTIAN.WAV NOT FOUND!");
//     while (1) {
//       delay(500);
//     }
//   }
//   Serial.println("Found YINTIAN.WAV, starting playback.");
  
//   audioSD.play("YINTIAN.WAV");
// }

// void loop() {
//   if (!audioSD.isPlaying()) {
//     audioSD.play("YINTIAN.WAV");
//   }
// }





//  Avec Midi Control::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <MIDI.h>  // Assurez-vous d'avoir installé la bibliothèque Arduino MIDI

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

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI); // Créer un port MIDI

AudioConnection patchCord0(audioSD, 0, vinyl, 0);
AudioConnection patchCord1(vinyl, 0, mix, 0);
AudioConnection patchCord2(mix, 0, out, 0); // Gauche
AudioConnection patchCord3(mix, 0, out, 1); // Droite

// Enregistrer les valeurs des paramètres précédents pour éviter les envois répétés
float previousGain = -1.0;
float previousScratch = -1.0;
float previousDust = -1.0;
float previousRumble = -1.0;
float previousMotor = -1.0;

void setup() {
  Serial.begin(9600);
  MIDI.begin(MIDI_CHANNEL_OMNI); // Écouter tous les canaux MIDI
  MIDI.setHandleControlChange(handleControlChange); // Écouter les événements CC

  audioShield.enable();
  audioShield.volume(2); // Définir le volume du bouclier audio
  AudioMemory(20); // Allouer de la mémoire audio
  mix.gain(0, 1);  // Définir le gain de l'entrée 0 (bruit)
  mix.gain(1, 0);  // Définir le gain de l'entrée 1 (audio SD)

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Impossible d'accéder à la carte SD");
      delay(500);
    }
  }

  // Jouer de la musique
  audioSD.play("YINTIAN.WAV");
}

void loop() {
  MIDI.read(); // Écouter les messages MIDI

  // Si la lecture de la musique se termine, relancer automatiquement
  if (!audioSD.isPlaying()) {
    audioSD.play("YINTIAN.WAV");
  }

  delay(100); // Éviter une exécution trop rapide
}

// Traiter les messages de contrôle MIDI
void handleControlChange(byte channel, byte controller, byte value) {
  float newValue = value / 127.0; // Mappage de MIDI 0-127 à 0.0 - 1.0
  
  switch (controller) {
    case 7: // CC7 contrôle le volume général (gain)
      if (fabs(newValue - previousGain) > 0.01) {
        vinyl.setParamValue("gain", newValue);
        previousGain = newValue;
        Serial.print("Gain: ");
        Serial.println(newValue);
      }
      break;
      
    case 10: // CC10 contrôle le son de scratch
      if (fabs(newValue - previousScratch) > 0.01) {
        vinyl.setParamValue("Scratch Trigger", newValue);
        previousScratch = newValue;
        Serial.print("Scratch: ");
        Serial.println(newValue);
      }
      break;

    case 11: // CC11 contrôle le son de poussière
      if (fabs(newValue - previousDust) > 0.01) {
        vinyl.setParamValue("Pop Trigger", newValue);
        previousDust = newValue;
        Serial.print("Poussière: ");
        Serial.println(newValue);
      }
      break;

    case 12: // CC12 contrôle le déclencheur de ronflement
      if (fabs(newValue - previousRumble) > 0.01) {
        vinyl.setParamValue("Rumble Trigger", newValue);
        previousRumble = newValue;
        Serial.print("Ronflement: ");
        Serial.println(newValue);
      }
      break;

    case 13: // CC13 contrôle le déclencheur de bruit moteur
      if (fabs(newValue - previousMotor) > 0.01) {
        vinyl.setParamValue("Motor Noise Trigger", newValue);
        previousMotor = newValue;
        Serial.print("Bruit moteur: ");
        Serial.println(newValue);
      }
      break;

    default:
      Serial.print("MIDI CC non géré: ");
      Serial.println(controller);
      break;
  }
}