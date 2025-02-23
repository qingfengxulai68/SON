// import("stdfaust.lib");

// // Contrôle du gain
// gainL = nentry("gain_left", 0.5, 0, 1, 0.01) : si.smoo;
// gainR = nentry("gain_right", 0.5, 0, 1, 0.01) : si.smoo;

// // Signal original (entrée stéréo)

// original_signalL = 0;
// original_signalR = 0;

// // Distorsion harmonique
// distortionL = original_signalL * (1 + (original_signalL * 0.4));
// distortionR = original_signalR * (1 + (original_signalR * 0.4));

// // Atténuation des hautes fréquences
// hf_attenuationL = distortionL : fi.lowpass(3, 8000);
// hf_attenuationR = distortionR : fi.lowpass(3, 8000);

// // Stéréo basse fréquence réduite à mono
// mono_bassL = (hf_attenuationL : fi.lowpass(3, 200)) :> _;
// mono_bassR = (hf_attenuationR : fi.lowpass(3, 200)) :> _;
// stereo_signalL = hf_attenuationL - (hf_attenuationL : fi.lowpass(3, 200)) + mono_bassL;
// stereo_signalR = hf_attenuationR - (hf_attenuationR : fi.lowpass(3, 200)) + mono_bassR;

// // Compression de la plage dynamique

// dynamic_compressionL = stereo_signalL : co.compressor_mono(3, -10, 0.01, 0.1);
// dynamic_compressionR = stereo_signalR : co.compressor_mono(3, -10, 0.01, 0.1);


// // Poussière et rayures
// white_noiseL = (no.noise : si.smoo) * 0.3;
// white_noiseR = (no.noise : si.smoo) * 0.3;


// scratch_triggerL = hslider("Left Scratch Trigger", 0.4, 0, 1, 0.01) : si.smoo;
// scratch_soundL = os.osc.phasor(0.1) : *(0.4) * scratch_triggerL;


// scratch_triggerR = hslider("Right Scratch Trigger", 0.4, 0, 1, 0.01) : si.smoo;
// scratch_soundR = os.osc.phasor(0.1) : *(0.4) * scratch_triggerR;


// dust_triggerL = hslider("Left Pop Trigger", 0.004, 0, 1, 0.001) : si.smoo;
// dust_soundL = os.pulsetrain(50, 100000) * (0.3) * dust_triggerL;

// dust_triggerR = hslider("Right Pop Trigger", 0.004, 0, 1, 0.001) : si.smoo;
// dust_soundR = os.pulsetrain(50, 100000) * (0.3) * dust_triggerR;

// // Bruit mécanique (grondement)
// rumble_triggerL = hslider("Left rumble Trigger", 0.04, 0, 1, 0.001) : si.smoo;
// rumbleL = (no.noise * rumble_triggerL) : fi.lowpass(3, 30);

// rumble_triggerR = hslider("Right rumble Trigger", 0.04, 0, 1, 0.001) : si.smoo;
// rumbleR = (no.noise * rumble_triggerR) : fi.lowpass(3, 30);

// // Bruit de moteur
// motor_noiseL_trigger = hslider("Motor Noise Left Trigger", 0.05, 0, 1, 0.001);
// motor_noiseR_trigger = hslider("Motor Noise Right Trigger", 0.05, 0, 1, 0.001);

// motor_noiseL = (os.osc(50) * 0.05 + os.osc(100) * 0.02) * motor_noiseL_trigger;
// motor_noiseR = (os.osc(50) * 0.05 + os.osc(100) * 0.02) * motor_noiseR_trigger;


// // Mixage final
// mixed_signalL = dynamic_compressionL + white_noiseL + scratch_soundL + dust_soundL + rumbleL + motor_noiseL;
// mixed_signalR = dynamic_compressionR + white_noiseR + scratch_soundR + dust_soundR + rumbleR + motor_noiseR;


// process = _ <: mixed_signalL * gainL, mixed_signalR * gainR;




// VERSION 2   VERSION 2   VERSION 2    VERSION 2    VERSION 2   VERSION 2 

import("stdfaust.lib");

// Gain ，de 0 a 1
gain = 0.5;

// Signal original (entrée stéréo)

original_signal = _;

// Distorsion harmonique
distortion = original_signal * (1 + (original_signal * 0.4));


// Atténuation des hautes fréquences
hf_attenuation = distortion : fi.lowpass(3, 8000);

// Stéréo basse fréquence réduite à mono
mono_bass = (hf_attenuation : fi.lowpass(3, 200)) :> _;

stereo_signal = hf_attenuation - (hf_attenuation : fi.lowpass(3, 200)) + mono_bass;

// Compression de la plage dynamique

dynamic_compression = stereo_signal : co.compressor_mono(3, -10, 0.01, 0.1);


// Poussière et rayures
white_noise = (no.noise : si.smoo) * 0.3;

// 划痕声音
scratch_sound = os.osc.phasor(0.1) * 0.4 ;

// 尘埃爆裂声音
dust_sound = os.pulsetrain(50, 100000) * 0.3 ;

// 机械噪音（低频隆隆声）
rumble = (no.noise * 0.1) : fi.lowpass(3, 30);

// 电机噪音
motor_noise = (os.osc(50) * 0.05 + os.osc(100) * 0.02) ;

// Mixage final

mixed_signal = (dynamic_compression + white_noise + scratch_sound + dust_sound + rumble + motor_noise) * gain;

process = mixed_signal <: _,_;













// DERNIERE  VERSION   DERNIERE  VERSION   DERNIERE  VERSION   DERNIERE  VERSION   DERNIERE  VERSION




import("stdfaust.lib");

// Gain ，de 0 a 1
gain = 0.5;

// Signal original (entrée stéréo)

original_signal = _;

// YESSSS: Distorsion harmonique
distortion = original_signal * (1 + (original_signal * 0.4));


// YESSSS: Atténuation des hautes fréquences
hf_attenuation = distortion : fi.lowpass(3, 1000);

// Compression de la plage dynamique

dynamic_compression = hf_attenuation : co.compressor_mono(3, -10, 0.01, 0.1);


// YESSSS:Poussière et rayures  0.7
white_noise = (no.noise : si.smoo) * 0.7;


// YESSSS:尘埃爆裂声音 0.01
dust_sound = os.pulsetrain(50, 100000) * 0.01;

// YESSSS:机械噪音（低频隆隆声） NO.NOISE * 1
rumble = (no.noise * 1) : fi.lowpass(3, 30);

// YESSSS:电机噪音
motor_noise = (os.osc(50) * 0.05 + os.osc(100) * 0.02) ;

// Mixage final

mixed_signal = (dynamic_compression + white_noise + dust_sound + rumble + motor_noise) * gain;

process = mixed_signal <: _,_;
