#include <Audio.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include "Vinyl.h"  // 引入Vinyl库，用于模拟黑胶效果
#include <MIDIUSB.h>  // 引入MIDIUSB库

#define SDCARD_CS_PIN 10  // SD卡的CS引脚定义

Vinyl vinyl;  // 创建Vinyl对象，用于处理黑胶效果

AudioOutputI2S out;  // 定义音频输出为I2S
AudioPlaySdWav audioSD;  // 定义从SD卡播放WAV文件的音频源
AudioControlSGTL5000 audioShield;  // 定义音频控制模块（如SGTL5000）
AudioMixer4 mix;  // 定义音频混音器

AudioConnection patchCord0(vinyl, 0, mix, 0);  // 连接Vinyl到混音器
AudioConnection patchCord1(audioSD, 0, mix, 1);  // 连接SD卡音频到混音器
AudioConnection patchCord2;  // 用于连接混音器到输出
AudioConnection patchCord3;  // 用于连接混音器到输出

void setup() {
  // 初始化音频模块
  audioShield.enable();  // 启用音频控制模块
  audioShield.volume(2);  // 设置音频模块的音量（可根据需要调整）

  // 初始化SD卡
  SPI.setMOSI(11);
  SPI.setSCK(13);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1);  // 如果无法访问SD卡，进入死循环
  }

  // 初始化音频库
  AudioMemory(4);  // 分配音频内存

  // 初始化MIDIUSB
  MIDI.begin(MIDI_CHANNEL_OMNI);  // 设置MIDI通道为全通道（Omni）
}

void loop() {
  // 检查是否有WAV文件正在播放
  if (!audioSD.isPlaying()) {
    audioSD.play("yintian.WAV");  // 播放SD卡中的song.WAV文件
  }

  // 将混音器的输出连接到音频输出
  patchCord2.connect(mix, 0, out, 0);
  patchCord3.connect(mix, 0, out, 1);

  // 使用Vinyl库处理黑胶效果
  vinyl.process();  // 调用Vinyl库的process方法，处理音频信号

  // MIDIUSB的主循环需要调用MIDI.read()来处理MIDI输入
  MIDI.read();

  delay(100);  // 简单的延时，避免过快重复播放
}