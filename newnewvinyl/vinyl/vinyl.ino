#include <DFRobotDFPlayerMini.h>

#include <DFRobotDFPlayerMini.h>

#include <DFRobotDFPlayerMini.h>

// //button功能删除后 && potentiometre删除后
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


// AudioConnection patchCord0(audioSD, 0, vinyl, 0);
// AudioConnection patchCord1(vinyl, 0, mix, 0);
// AudioConnection patchCord2(mix, 0, out, 0); 
// AudioConnection patchCord3(mix, 0, out, 1); 

// void setup() {
//   Serial.begin(9600);
//   audioShield.enable();
//   audioShield.volume(0.5); // 设置音频盾的音量
//   AudioMemory(20); // 分配音频内存
//   mix.gain(0, 1);  // 设置输入 1（SD卡音频）的增益
//   mix.gain(1, 0); // 设置输入 0 （噪音）的增益

//   SPI.setMOSI(SDCARD_MOSI_PIN);
//   SPI.setSCK(SDCARD_SCK_PIN);
//   if (!(SD.begin(SDCARD_CS_PIN))) {
//     while (1) {
//       Serial.println("Unable to access the SD card");
//       delay(500);
//     }
//   }
// }

// void loop() {

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
//   

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

// #include <Audio.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>
// #include <USBHost_t36.h>

// #include "Vinyl.h"
// #include <cmath>

// #define SDCARD_CS_PIN 10
// #define SDCARD_MOSI_PIN 11
// #define SDCARD_SCK_PIN 13

// Vinyl vinyl;
// AudioOutputI2S out;
// AudioPlaySdWav audioSD;
// AudioControlSGTL5000 audioShield;
// AudioMixer4 mix;

// AudioConnection patchCord0(audioSD, 0, vinyl, 0);
// AudioConnection patchCord1(vinyl, 0, mix, 0);
// AudioConnection patchCord2(mix, 0, out, 0); // Gauche
// AudioConnection patchCord3(mix, 0, out, 1); // Droite

// // Enregistrer les valeurs des paramètres précédents pour éviter les envois répétés
// float previousGain = -1.0;
// float previousScratch = -1.0;
// float previousDust = -1.0;
// float previousRumble = -1.0;
// float previousMotor = -1.0;

// void setup() {
//   Serial.begin(9600);

//   usbMIDI.setHandleControlChange(handleControlChange);
//   usbMIDI.begin();

//   audioShield.enable();
//   audioShield.volume(0.5);
//   AudioMemory(20);
//   mix.gain(0, 0);  // Définir le gain de l'entrée 0 (bruit)
//   mix.gain(1, 1);  // Définir le gain de l'entrée 1 (audio SD)

  // audioShield.enable();
  // audioShield.volume(2); // Définir le volume du bouclier audio
  // AudioMemory(20); // Allouer de la mémoire audio
  // mix.gain(0, 1);  // Définir le gain de l'entrée 0 (bruit)
  // mix.gain(1, 0);  // Définir le gain de l'entrée 1 (audio SD)

//   Serial.println("Checking SD Card...");
//   if (!SD.begin(SDCARD_CS_PIN)) {
//     Serial.println("SD Card initialization failed!");
//     while (1) delay(500);
//   }
//   Serial.println("SD Card OK.");

//   if (!SD.exists("YINTIAN.WAV")) {
//     Serial.println("ERROR: YINTIAN.WAV NOT FOUND!");
//     while (1) delay(500);
//   }
//   Serial.println("Found YINTIAN.WAV, ready to play.");
// }

// // Fonction pour gérer les messages Control Change (volume)
// void handleControlChange(byte channel, byte control, byte value) {
//   float newValue = value / 127.0;  // Convertir 0-127 en 0.0-1.0
//   switch (control) {
//     case 7: // CC7 contrôle le volume général (gain)
//         audioShield.volume(newValue);
//         Serial.print("Volume réglé à : ");
//         Serial.println(newValue);
//       break;
//   }
// }

// void loop() {
//   usbMIDI.read();  // Vérifie les messages MIDI entrants

//   if (!audioSD.isPlaying()) {
//     audioSD.play("YINTIAN.WAV");
//   }
//   delay(100);
// }


// ------------------------------------Yafei----------------------------------------------------------


//  Avec Midi Control::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// #include <Audio.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>
// #include <MIDI.h>  // Assurez-vous d'avoir installé la bibliothèque Arduino MIDI

// #include "Vinyl.h"
// #include <cmath>

// #define SDCARD_CS_PIN 10
// #define SDCARD_MOSI_PIN 11
// #define SDCARD_SCK_PIN 13

// Vinyl vinyl;
// AudioOutputI2S out;
// AudioPlaySdWav audioSD;
// AudioControlSGTL5000 audioShield;
// AudioMixer4 mix;

// MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI); // Créer un port MIDI

// AudioConnection patchCord0(audioSD, 0, vinyl, 0);
// AudioConnection patchCord1(vinyl, 0, mix, 0);
// AudioConnection patchCord2(mix, 0, out, 0); // Gauche
// AudioConnection patchCord3(mix, 0, out, 1); // Droite

// // Enregistrer les valeurs des paramètres précédents pour éviter les envois répétés
// float previousGain = -1.0;
// float previousScratch = -1.0;
// float previousDust = -1.0;
// float previousRumble = -1.0;
// float previousMotor = -1.0;

// void setup() {
//   Serial.begin(9600);
//   MIDI.begin(MIDI_CHANNEL_OMNI); // Écouter tous les canaux MIDI
//   MIDI.setHandleControlChange(handleControlChange); // Écouter les événements CC

//   audioShield.enable();
//   audioShield.volume(0.5); // Définir le volume du bouclier audio
//   AudioMemory(20); // Allouer de la mémoire audio
//   mix.gain(0, 1);  // Définir le gain de l'entrée 0 (bruit)
//   mix.gain(1, 0);  // Définir le gain de l'entrée 1 (audio SD)

//   SPI.setMOSI(SDCARD_MOSI_PIN);
//   SPI.setSCK(SDCARD_SCK_PIN);

//   Serial.println("Checking SD Card...");
//   if (!SD.begin(SDCARD_CS_PIN)) {
//     Serial.println("SD Card initialization failed!");
//     while (1) delay(500);
//   }
//   Serial.println("SD Card OK.");

//   if (!SD.exists("YINTIAN.WAV")) {
//     Serial.println("ERROR: YINTIAN.WAV NOT FOUND!");
//     while (1) delay(500);
//   }
//   Serial.println("Found YINTIAN.WAV, ready to play.");
// }

// void loop() {
//   MIDI.read(); // Écouter les messages MIDI

//   // Si la lecture de la musique se termine, relancer automatiquement
//   if (!audioSD.isPlaying()) {
//     audioSD.play("YINTIAN.WAV");
//   }
//   delay(100); // Éviter une exécution trop rapide
// }

// // Traiter les messages de contrôle MIDI
// void handleControlChange(byte channel, byte controller, byte value) {
//   float newValue = value / 127.0; // Mappage de MIDI 0-127 à 0.0 - 1.0
  
//   switch (controller) {
//     case 7: // CC7 contrôle le volume général (gain)
//       if (fabs(newValue - previousGain) > 0.01) {
//         float newVolume = value / 100.0;  // Convertir 0-127 en 0.0-1.0
//         audioShield.volume(newVolume);
//         Serial.print("Volume réglé à : ");
//         Serial.println(newVolume);
//       }
//       break;
    
//     case 8:
//       if (fabs(newValue - previousScratch) > 0.01) {
//         vinyl.setParamValue("White Noise", newValue);
//         previousScratch = newValue;
//         Serial.print("Bruit : ");
//         Serial.println(newValue);
//       }
//       break;

//     case 9: // CC8 contrôle le son de scratch
//       if (fabs(newValue - previousScratch) > 0.01) {
//         vinyl.setParamValue("Scratch Trigger", newValue);
//         previousScratch = newValue;
//         Serial.print("Scratch: ");
//         Serial.println(newValue);
//       }
//       break;

//     case 10: // CC9 contrôle le son de poussière
//       if (fabs(newValue - previousDust) > 0.01) {
//         vinyl.setParamValue("Pop Trigger", newValue);
//         previousDust = newValue;
//         Serial.print("Poussière: ");
//         Serial.println(newValue);
//       }
//       break;

//     case 11: // CC10 contrôle le déclencheur de ronflement
//       if (fabs(newValue - previousRumble) > 0.01) {
//         vinyl.setParamValue("Rumble Trigger", newValue);
//         previousRumble = newValue;
//         Serial.print("Ronflement: ");
//         Serial.println(newValue);
//       }
//       break;

//     case 12: // CC11 contrôle le déclencheur de bruit moteur
//       if (fabs(newValue - previousMotor) > 0.01) {
//         vinyl.setParamValue("Motor Noise Trigger", newValue);
//         previousMotor = newValue;
//         Serial.print("Bruit moteur: ");
//         Serial.println(newValue);
//       }
//       break;

//     default:
//       Serial.print("MIDI CC non géré: ");
//       Serial.println(controller);
//       break;
//   }
// }

#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <USBHost_t36.h>
#include <cstring> 

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

int titleIndex = 0;
bool titleReceived = false;
bool isPlaying = true;
char receivedTitle[30] = "";

void setup() {
  Serial.begin(9600);

  usbMIDI.begin();
  usbMIDI.setHandleControlChange(handleControlChange);

  audioShield.enable();
  audioShield.volume(0.2);
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
    playFile(receivedTitle);
    titleReceived = false;
  }

  delay(100);
}

void handleControlChange(byte channel, byte controller, byte value) {
  float newValue = value / 127.0;
  
  switch (controller) {
    // case 30:
    //   newValue = ((value * 40) / 127) - 40;
    //   vinyl.setParamValue("compress_threshold", newValue);
    //   Serial.print("compress_threshold: ");
    //   Serial.println(newValue);
    // case 31:
    //   newValue = value / 12.7;
    //   vinyl.setParamValue("compress_ratio", newValue);
    //   Serial.print("compress_ratio: ");
    //   Serial.println(newValue);
    // case 32:
    //   vinyl.setParamValue("compress_attack", newValue);
    //   Serial.print("compress_attack: ");
    //   Serial.println(newValue);
    // case 33:
    //   vinyl.setParamValue("compress_release", newValue);
    //   Serial.print("compress_release: ");
    //   Serial.println(newValue);
    case 4:
      newValue = 20.0 * pow(20000.0/20.0, (value - 1.0)/(127.0-1.0));
      vinyl.setParamValue("lowpass_freq", newValue);
      Serial.print("lowpass_freq: ");
      Serial.println(newValue);
      break;
    case 5:
      vinyl.setParamValue("distortion", newValue);
      Serial.print("distortion: ");
      Serial.println(newValue);
      break;
    // case 6:
    //   vinyl.setParamValue("gain", newValue);
    //   Serial.print("gain: ");
    //   Serial.println(newValue);
      break;
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
      vinyl.setParamValue("echo_feedback", newValue);
      Serial.print("echo_feedback: ");
      Serial.println(newValue);
      break;

    case 10:  // Son de poussière
      newValue = value / 1270.0;
      vinyl.setParamValue("dust", newValue);
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

    case 13:  // Bruit moteur
      vinyl.setParamValue("echo_delay", newValue);
      Serial.print("echo_delay: ");
      Serial.println(newValue);
      break;

    case 14:  // Play/Pause
      if (value == 127) {  
        // toggle play/pause state
        audioSD.togglePlayPause();
      }
      break;

    case 26:
      if (value == 0) {
          strcpy(receivedTitle, "yintian.wav");  // Copier le nom du fichier
      }
      else if (value == 1) {
          strcpy(receivedTitle, "k.wav");
      }
      else if (value == 3) {
          strcpy(receivedTitle, "beautifulgirls.wav");
      }
      else {
          strcpy(receivedTitle, "loststars.wav");
      }
      titleReceived = true;
      Serial.print("Titre reçu : ");
      Serial.println(receivedTitle);
      break;

      default:
        Serial.print("MIDI CC non géré: ");
        Serial.println(controller);
        break;
  }
}

void playFile(char* receivedTitle) {
  Serial.print("Playing file: ");
  Serial.println(receivedTitle);
  audioSD.play(receivedTitle);

  delay(5);
}




