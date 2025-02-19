import("stdfaust.lib");

// 增益控制
gain = nentry("gain", 0.5, 0, 1, 0.01) : si.smoo;

// 白噪声（模拟唱片底噪）
white_noise = (no.noise : si.smoo) * 0.4;

// 划痕声（随机触发）
scratch_trigger = button("Scratch Trigger") : si.debounce(0.1) : si.smoo;
scratch_sound = os.osc.phasor(0.1) : *(0.4) * scratch_trigger;

// 爆裂声（随机触发）
dust_trigger = button("Pop Trigger") : si.debounce(0.005) : si.smoo;
dust_sound = os.pulsetrain(50, 100000) * (0.3) * dust_trigger;

// 随机调制频率（模拟 Wow and Flutter 效果）
wow_flutter = 0.001 * no.noise : si.smoo;
modulated_signal = original_signal * (1 + wow_flutter);

// 混合信号
mixed_signal = modulated_signal + white_noise + scratch_sound + dust_sound;

// 带通滤波器（模拟黑胶唱片的频率响应）
bandpass_signal = mixed_signal : fi.bandpass(3, 85, 6000);

// 动态范围压缩（模拟黑胶唱片的动态范围）
compressor = si.comp(0.5, 2, 0.01, 0.001, 0.01);
compressed_signal = bandpass_signal : compressor;

// 输出信号（立体声）
process = compressed_signal <: _,_;