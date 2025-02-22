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

#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13

AudioOutputI2S out;
AudioPlaySdWav audioSD;
AudioControlSGTL5000 audioShield;
AudioMixer4 mix;

AudioConnection patchCord0(audioSD, 0, mix, 0);
AudioConnection patchCord1(mix, 0, out, 0);
AudioConnection patchCord2(mix, 0, out, 1);

void setup() {
  Serial.begin(9600);

  audioShield.enable();
  audioShield.volume(2);
  AudioMemory(4);
  mix.gain(0, 0.5);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  
  Serial.println("Checking SD Card...");
  if (!SD.begin(SDCARD_CS_PIN)) {
    Serial.println("SD Card initialization failed!");
    while (1) {
      delay(500);
    }
  }
  Serial.println("SD Card OK.");

  if (!SD.exists("YINTIAN.WAV")) {
    Serial.println("ERROR: YINTIAN.WAV NOT FOUND!");
    while (1) {
      delay(500);
    }
  }
  Serial.println("Found YINTIAN.WAV, starting playback.");
  
  audioSD.play("YINTIAN.WAV");
}

// MIDI_CREATE_DEFAULT_INSTANCE();

// void setup() {
//   MIDI.begin(MIDI_CHANNEL_OMNI);  // Ecoute sur tous les canaux
//   Serial.begin(9600);  // Si vous voulez afficher des informations de débogage
// }

void loop() {
  if (!audioSD.isPlaying()) {
    audioSD.play("YINTIAN.WAV");
  }
}





