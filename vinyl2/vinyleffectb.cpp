/* ------------------------------------------------------------
name: "vinyleffectb"
Code generated with Faust 2.79.0 (https://faust.grame.fr)
Compilation options: -lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class mydspSIG0 {
	
  private:
	
	int iVec0[2];
	int iRec0[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iRec0[l1] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec0[0] = 1;
			iRec0[0] = (iVec0[1] + iRec0[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * float(iRec0[0]));
			iVec0[1] = iVec0[0];
			iRec0[1] = iRec0[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[65536];
static float mydsp_faustpower2_f(float value) {
	return value * value;
}

class mydsp : public dsp {
	
 private:
	
	int iVec1[2];
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec1[2];
	float fConst2;
	float fRec2[2];
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	int iRec5[2];
	float fConst9;
	float fConst10;
	FAUSTFLOAT fHslider1;
	float fRec6[2];
	float fVec2[2];
	float fConst11;
	float fRec4[2];
	float fRec3[3];
	float fRec7[2];
	float fVec3[2];
	int IOTA0;
	float fVec4[4096];
	float fConst12;
	int iConst13;
	int iConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	FAUSTFLOAT fHslider2;
	float fRec8[2];
	float fConst18;
	FAUSTFLOAT fHslider3;
	float fRec9[2];
	float fConst19;
	float fRec10[2];
	float fConst20;
	float fRec11[2];
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fRec15[2];
	float fRec14[3];
	float fConst27;
	float fConst28;
	float fRec13[2];
	float fConst29;
	float fConst30;
	float fRec12[2];
	FAUSTFLOAT fEntry0;
	float fRec16[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec19[2];
	float fVec5[2];
	float fRec18[2];
	float fRec17[3];
	FAUSTFLOAT fHslider6;
	float fRec20[2];
	FAUSTFLOAT fHslider7;
	float fRec21[2];
	FAUSTFLOAT fEntry1;
	float fRec22[2];
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/amp_follower_ar:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.2.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.21.0");
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("compressors.lib/compression_gain_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compression_gain_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compression_gain_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_lad_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_lad_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_lad_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/compressor_mono:author", "Julius O. Smith III");
		m->declare("compressors.lib/compressor_mono:copyright", "Copyright (C) 2014-2020 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("compressors.lib/compressor_mono:license", "MIT-style STK-4.3 license");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "1.6.0");
		m->declare("filename", "vinyleffectb.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.6.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "vinyleffectb");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.1");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/sawN:author", "Julius O. Smith III");
		m->declare("oscillators.lib/sawN:license", "STK-4.3");
		m->declare("oscillators.lib/version", "1.5.1");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/onePoleSwitching:author", "Jonatan Liljedahl, revised by Dario Sanfilippo");
		m->declare("signals.lib/onePoleSwitching:licence", "STK-4.3");
		m->declare("signals.lib/version", "1.6.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(65536, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = 1e+02f / fConst0;
		fConst2 = 5e+01f / fConst0;
		fConst3 = std::tan(94.24778f / fConst0);
		fConst4 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fConst3));
		fConst5 = 1.0f / fConst3;
		fConst6 = (fConst5 + -1.0f) / fConst3 + 1.0f;
		fConst7 = 1.0f / ((fConst5 + 1.0f) / fConst3 + 1.0f);
		fConst8 = 1.0f - fConst5;
		fConst9 = 44.1f / fConst0;
		fConst10 = 1.0f - fConst9;
		fConst11 = 1.0f / (fConst5 + 1.0f);
		fConst12 = std::max<float>(0.0f, std::min<float>(2047.0f, 2e+03f * fConst0));
		iConst13 = int(fConst12);
		iConst14 = iConst13 + 1;
		fConst15 = std::floor(fConst12);
		fConst16 = fConst12 - fConst15;
		fConst17 = fConst15 + (1.0f - fConst12);
		fConst18 = 0.0015f * fConst0;
		fConst19 = 1.0f / fConst0;
		fConst20 = 2.0535662e-08f / fConst0;
		fConst21 = std::tan(25132.742f / fConst0);
		fConst22 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fConst21));
		fConst23 = 1.0f / fConst21;
		fConst24 = (fConst23 + -1.0f) / fConst21 + 1.0f;
		fConst25 = 1.0f / ((fConst23 + 1.0f) / fConst21 + 1.0f);
		fConst26 = (1.0f - fConst23) / (fConst23 + 1.0f);
		fConst27 = std::exp(-(1e+01f / fConst0));
		fConst28 = std::exp(-fConst1);
		fConst29 = std::exp(-(2e+02f / fConst0));
		fConst30 = 0.6666667f * (1.0f - fConst29);
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.05f);
		fHslider1 = FAUSTFLOAT(0.04f);
		fHslider2 = FAUSTFLOAT(0.004f);
		fHslider3 = FAUSTFLOAT(0.4f);
		fEntry0 = FAUSTFLOAT(0.5f);
		fHslider4 = FAUSTFLOAT(0.05f);
		fHslider5 = FAUSTFLOAT(0.04f);
		fHslider6 = FAUSTFLOAT(0.004f);
		fHslider7 = FAUSTFLOAT(0.4f);
		fEntry1 = FAUSTFLOAT(0.5f);
	}
	
	virtual void instanceClear() {
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			iVec1[l2] = 0;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fRec1[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec2[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			iRec5[l5] = 0;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec6[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec4[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec3[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fVec3[l11] = 0.0f;
		}
		IOTA0 = 0;
		for (int l12 = 0; l12 < 4096; l12 = l12 + 1) {
			fVec4[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 2; l13 = l13 + 1) {
			fRec8[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 2; l14 = l14 + 1) {
			fRec9[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec10[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec11[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 2; l17 = l17 + 1) {
			fRec15[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 3; l18 = l18 + 1) {
			fRec14[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 2; l20 = l20 + 1) {
			fRec12[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec16[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec19[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 2; l23 = l23 + 1) {
			fVec5[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec18[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 3; l25 = l25 + 1) {
			fRec17[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 2; l26 = l26 + 1) {
			fRec20[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec21[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec22[l28] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual mydsp* clone() {
		return new mydsp();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("vinyleffectb");
		ui_interface->addHorizontalSlider("Left Pop Trigger", &fHslider2, FAUSTFLOAT(0.004f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Left Scratch Trigger", &fHslider3, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Left rumble Trigger", &fHslider1, FAUSTFLOAT(0.04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Motor Noise Left Trigger", &fHslider0, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Motor Noise Right Trigger", &fHslider4, FAUSTFLOAT(0.05f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Right Pop Trigger", &fHslider6, FAUSTFLOAT(0.004f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Right Scratch Trigger", &fHslider7, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Right rumble Trigger", &fHslider5, FAUSTFLOAT(0.04f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addNumEntry("gain_left", &fEntry0, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addNumEntry("gain_right", &fEntry1, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = float(fHslider0);
		float fSlow1 = fConst9 * float(fHslider1);
		float fSlow2 = fConst9 * float(fHslider2);
		float fSlow3 = fConst9 * float(fHslider3);
		float fSlow4 = fConst9 * float(fEntry0);
		float fSlow5 = float(fHslider4);
		float fSlow6 = fConst9 * float(fHslider5);
		float fSlow7 = fConst9 * float(fHslider6);
		float fSlow8 = fConst9 * float(fHslider7);
		float fSlow9 = fConst9 * float(fEntry1);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec1[0] = 1;
			int iTemp0 = 1 - iVec1[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fConst1 + fRec1[1]);
			fRec1[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = ((iTemp0) ? 0.0f : fConst2 + fRec2[1]);
			fRec2[0] = fTemp2 - std::floor(fTemp2);
			float fTemp3 = 0.05f * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec2[0]), 65535))] + 0.02f * ftbl0mydspSIG0[std::max<int>(0, std::min<int>(int(65536.0f * fRec1[0]), 65535))];
			iRec5[0] = 1103515245 * iRec5[1] + 12345;
			float fTemp4 = float(iRec5[0]);
			fRec6[0] = fSlow1 + fConst10 * fRec6[1];
			float fTemp5 = fRec6[0] * fTemp4;
			fVec2[0] = fTemp5;
			fRec4[0] = fConst11 * (4.656613e-10f * (fTemp5 + fVec2[1]) - fConst8 * fRec4[1]);
			fRec3[0] = fRec4[0] - fConst7 * (fConst6 * fRec3[2] + fConst4 * fRec3[1]);
			float fTemp6 = ((iTemp0) ? 0.0f : fConst2 + fRec7[1]);
			fRec7[0] = fTemp6 - std::floor(fTemp6);
			float fTemp7 = mydsp_faustpower2_f(2.0f * fRec7[0] + -1.0f);
			fVec3[0] = fTemp7;
			float fTemp8 = float(iVec1[1]) * (fTemp7 - fVec3[1]);
			fVec4[IOTA0 & 4095] = fTemp8;
			float fTemp9 = fTemp8 - fConst17 * fVec4[(IOTA0 - iConst13) & 4095] - fConst16 * fVec4[(IOTA0 - iConst14) & 4095];
			fRec8[0] = fSlow2 + fConst10 * fRec8[1];
			fRec9[0] = fSlow3 + fConst10 * fRec9[1];
			float fTemp10 = ((iTemp0) ? 0.0f : fRec10[1] + fConst19 * float(input0[i0]));
			fRec10[0] = fTemp10 - std::floor(fTemp10);
			fRec11[0] = fConst20 * fTemp4 + fConst10 * fRec11[1];
			fRec15[0] = -(fConst26 * fRec15[1]);
			fRec14[0] = fRec15[0] - fConst25 * (fConst24 * fRec14[2] + fConst22 * fRec14[1]);
			float fTemp11 = fRec14[2] + fRec14[0] + 2.0f * fRec14[1];
			float fTemp12 = std::fabs(fConst25 * fTemp11);
			float fTemp13 = ((fTemp12 > fRec13[1]) ? fConst28 : fConst27);
			fRec13[0] = fTemp12 * (1.0f - fTemp13) + fRec13[1] * fTemp13;
			fRec12[0] = fConst29 * fRec12[1] - fConst30 * std::max<float>(2e+01f * std::log10(std::max<float>(1.1754944e-38f, fRec13[0])) + 1e+01f, 0.0f);
			float fTemp14 = fConst25 * fTemp11 * std::pow(1e+01f, 0.05f * fRec12[0]) + 0.3f * fRec11[0];
			fRec16[0] = fSlow4 + fConst10 * fRec16[1];
			output0[i0] = FAUSTFLOAT(fRec16[0] * (fTemp14 + 0.04f * fRec10[0] * fRec9[0] + fConst18 * fRec8[0] * fTemp9 + fConst7 * (fRec3[2] + fRec3[0] + 2.0f * fRec3[1]) + fSlow0 * fTemp3));
			fRec19[0] = fSlow6 + fConst10 * fRec19[1];
			float fTemp15 = fRec19[0] * fTemp4;
			fVec5[0] = fTemp15;
			fRec18[0] = fConst11 * (4.656613e-10f * (fTemp15 + fVec5[1]) - fConst8 * fRec18[1]);
			fRec17[0] = fRec18[0] - fConst7 * (fConst6 * fRec17[2] + fConst4 * fRec17[1]);
			fRec20[0] = fSlow7 + fConst10 * fRec20[1];
			fRec21[0] = fSlow8 + fConst10 * fRec21[1];
			fRec22[0] = fSlow9 + fConst10 * fRec22[1];
			output1[i0] = FAUSTFLOAT(fRec22[0] * (fTemp14 + 0.04f * fRec10[0] * fRec21[0] + fConst18 * fRec20[0] * fTemp9 + fConst7 * (fRec17[2] + fRec17[0] + 2.0f * fRec17[1]) + fSlow5 * fTemp3));
			iVec1[1] = iVec1[0];
			fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
			iRec5[1] = iRec5[0];
			fRec6[1] = fRec6[0];
			fVec2[1] = fVec2[0];
			fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1];
			fRec3[1] = fRec3[0];
			fRec7[1] = fRec7[0];
			fVec3[1] = fVec3[0];
			IOTA0 = IOTA0 + 1;
			fRec8[1] = fRec8[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec15[1] = fRec15[0];
			fRec14[2] = fRec14[1];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fVec5[1] = fVec5[0];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec22[1] = fRec22[0];
		}
	}

};

#endif
