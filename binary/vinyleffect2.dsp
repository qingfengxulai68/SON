declare filename "vinyleffect.dsp";
declare name "vinyleffect";
import("stdfaust.lib");

// Contrôle du gain
gain = nentry("gain", 0.5, 0, 1, 0.01) : si.smoo;

// Signal original (entrée stéréo)
original_signal = _, _;

// Bruit mécanique (grondement)
// 机械噪声（地噪 + 电机噪声）
rumble = no.noise * 0.1 : fi.lowpass(3, 30);

// Bruit de moteur
// 机械噪声（地噪 + 电机噪声）
motor_noise = os.osc(50) * 0.05 + os.osc(100) * 0.02;

// Distorsion harmonique (privilégiant la deuxième harmonique)
// 谐波失真（侧重于二次谐波）
distortion = original_signal * (1 + (original_signal * 0.4));

// Atténuation des hautes fréquences (simuler perte de détail sur vinyle)
// 高频衰减
hf_attenuation = distortion : fi.lowpass(3, 8000);

// Stéréo basse fréquence réduite à mono
// 低频单声道处理
mono_bass = (hf_attenuation : fi.lowpass(3, 200)) :> _;
stereo_signal = hf_attenuation - (hf_attenuation : fi.lowpass(3, 200)) + mono_bass;

// Compression de la plage dynamique (douce pour simuler vinyle)
// 动态压缩
dynamic_compression = stereo_signal : comp.compressor(3, -10, 3, 0.01, 0.1);

// Poussière et rayures
// 表面噪声（灰尘 & 划痕）
white_noise = (no.noise : si.smoo) * 0.3;
scratch_sound = os.osc.phasor(0.1) * 0.4;
dust_sound = os.pulsetrain(50, 100000) * 0.3;

// Mixage final
mixed_signal = dynamic_compression + white_noise + scratch_sound + dust_sound + rumble + motor_noise;

process = _ <: mixed_signal * gain, mixed_signal * gain;







