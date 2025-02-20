#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>

// 定义音频模块的连接
AudioPlaySdWav player;  // 用于播放WAV文件
AudioOutputI2S i2s;     // 使用I2S输出音频
AudioConnection patchCord0(player, 0, i2s, 0);  // 连接播放器到音频输出
AudioControlSGTL5000 audioShield;  // 控制音频模块

void setup() {
  // 初始化音频模块
  audioShield.enable();
  audioShield.inputSelect(AUDIO_INPUT_LINEIN);  // 设置输入源为线路输入
  audioShield.volume(0.5);  // 设置音量（0.0到1.0）

  // 初始化SD卡
  if (!SD.begin()) {
    while (1);  // 如果SD卡初始化失败，进入死循环
  }

  // 播放WAV文件
  player.play("yintian.wav");
}

void loop() {
  // 主循环为空，音频播放由Audio Library自动处理
}