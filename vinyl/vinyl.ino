#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "Vinyl.h"
#include <MIDIUSB.h>  // 引入MIDIUSB库，用于USB MIDI通信
// Inclure la bibliothèque MIDIUSB pour la communication MIDI via USB

#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11
#define SDCARD_SCK_PIN 13
#define PLAY_BUTTON_PIN 0

Vinyl vinyl;

AudioOutputI2S out;
AudioPlaySdWav audioSD;
AudioControlSGTL5000 audioShield;
AudioMixer4 mix;

AudioConnection patchCord0(vinyl, 0, mix, 0);
AudioConnection patchCord1(audioSD, 0, mix, 1);
AudioConnection patchCord2;
AudioConnection patchCord3;

void setup() {
  // 初始化音频模块
  audioShield.enable();
  audioShield.volume(2);  // 设置音频模块的音量
  // Initialiser le module audio
  // Définir le volume du module audio

  AudioMemory(4);  // 分配音频内存
  // Allouer de la mémoire pour l'audio

  pinMode(PLAY_BUTTON_PIN, INPUT);  // 设置播放按钮引脚为输入
  // Configurer le broche du bouton de lecture en entrée

  // 设置音频混音器的增益
  mix.gain(0, 5);  // 设置Vinyl输入的增益
  mix.gain(1, 0.15);  // 设置SD卡音频的增益
  // Définir le gain du mélangeur audio
  // Définir le gain de l'entrée Vinyl
  // Définir le gain de l'audio de la carte SD

  // 初始化SD卡
  Serial.begin(9600);  // 仅用于初始化SD卡时的调试信息
  Serial.println("Initializing SD card...");
  // Initialiser la carte SD
  // Utilisé uniquement pour les informations de débogage lors de l'initialisation de la carte SD
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  } else {
    Serial.println("Initialize successfully");
  }
  // Si la carte SD ne peut pas être accédée, afficher un message d'erreur
  // Sinon, confirmer l'initialisation réussie

  // 初始化MIDIUSB
  MIDI.begin(MIDI_CHANNEL_OMNI);  // 设置MIDI通道为全通道（Omni）
  // Initialiser MIDIUSB
  // Définir le canal MIDI en mode Omni (tous les canaux)
}

void loop() {
  int knobValue = analogRead(A4);  // 读取音量旋钮的值
  int playButtonState = digitalRead(PLAY_BUTTON_PIN);  // 读取播放按钮的状态
  float gain = map(knobValue, 0, 1023, 0, 127);  // 将旋钮值映射到MIDI CC值范围（0-127）
  // Lire la valeur du potentiomètre de volume
  // Lire l'état du bouton de lecture
  // Mapper la valeur du potentiomètre à la plage des valeurs MIDI CC (0-127)

  // 音量控制：发送MIDI控制变化（CC）消息
  static float previousGainValue = -1.0;
  float gainValue = knobValue / 102.3;
  if (fabs(gainValue - previousGainValue) > 0.1) {
    MIDI.sendControlChange(7, gain, 1);  // 发送MIDI CC消息（控制器号7，值为`gain`，通道1）
    previousGainValue = gainValue;
  }
  // Contrôle de volume : envoyer un message MIDI de changement de contrôle (CC)
  // Si la valeur du gain a changé suffisamment, envoyer un message MIDI CC (contrôleur 7, valeur `gain`, canal 1)

  // 播放按钮逻辑
  if (playButtonState == HIGH && audioSD.isPlaying() == false) {
    // 如果播放按钮按下且音频未播放，则开始播放音频
    MIDI.sendNoteOn(60, 127, 1);  // 发送MIDI音符消息（音符60，力度127，通道1）
    delay(800);  // 延时避免重复触发
    audioSD.play("song.WAV");  // 播放SD卡中的音频文件
    patchCord2.connect(mix, 0, out, 0);  // 连接音频路径
    patchCord3.connect(mix, 0, out, 1);
    delay(500);
  }
  // Logique du bouton de lecture
  // Si le bouton est enfoncé et que l'audio n'est pas en train de jouer, commencer la lecture
  // Envoyer un message MIDI de note (note 60, vélocité 127, canal 1)
  // Jouer le fichier audio sur la carte SD
  // Connecter les chemins audio

  else if (playButtonState == HIGH && audioSD.isPlaying() == true) {
    // 如果播放按钮按下且音频正在播放，则停止播放
    MIDI.sendNoteOff(60, 127, 1);  // 发送MIDI音符关闭消息（音符60，力度127，通道1）
    delay(100);  // 延时避免重复触发
    audioSD.stop();  // 停止播放音频
    patchCord2.disconnect();  // 断开音频路径
    patchCord3.disconnect();
    delay(500);
  }
  // Si le bouton est enfoncé et que l'audio est en train de jouer, arrêter la lecture
  // Envoyer un message MIDI de fin de note (note 60, vélocité 127, canal 1)
  // Arrêter la lecture de l'audio
  // Déconnecter les chemins audio

  delay(100);  // 主循环延时
  // Délai dans la boucle principale
}