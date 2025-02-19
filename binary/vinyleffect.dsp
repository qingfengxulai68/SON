declare filename "vinyleffect.dsp";
declare name "vinyleffect";
import("stdfaust.lib");

gain = nentry("gain", 0.5, 0, 1, 0.01) : si.smoo;

original_signal = 0;
white_noise = (no.noise : si.smoo) * 0.4;

scratch_trigger_1 = hslider("Left Scratch Trigger", 0.4, 0, 1, 0.01) : si.smoo;
scratch_sound_1 = os.osc.phasor(0.1) : *(0.4) * scratch_trigger_1;

scratch_trigger_2 = hslider("Right Scratch Trigger", 0.4, 0, 1, 0.01) : si.smoo;
scratch_sound_2 = os.osc.phasor(0.1) : *(0.4) * scratch_trigger_2;



dust_trigger_1 = hslider("Left Pop Trigger", 0.004, 0, 1, 0.001) : si.smoo;
dust_sound_1 = os.pulsetrain(50, 100000) * (0.3) * dust_trigger_1;

dust_trigger_2 = hslider("Right Pop Trigger", 0.004, 0, 1, 0.001) : si.smoo;
dust_sound_2 = os.pulsetrain(50, 100000) * (0.3) * dust_trigger_2;


mixed_signal_1 = original_signal + white_noise + scratch_sound_1 + dust_sound_1;
mixed_signal_2 = original_signal + white_noise + scratch_sound_2 + dust_sound_2;

bandpass_signal_1 = mixed_signal_1 : fi.bandpass(3, 85, 6000);
bandpass_signal_2 = mixed_signal_2 : fi.bandpass(3, 85, 6000);

process = _ <: bandpass_signal_1,bandpass_signal_2;

