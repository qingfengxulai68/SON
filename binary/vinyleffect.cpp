/* ------------------------------------------------------------
name: "vinyleffect"
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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float mydsp_faustpower3_f(float value) {
	return value * value * value;
}
static float mydsp_faustpower4_f(float value) {
	return value * value * value * value;
}

class mydsp : public dsp {
	
 private:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	float fConst3;
	float fConst4;
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	float fConst18;
	int iVec0[2];
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fConst23;
	float fConst24;
	float fConst25;
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec2[2];
	float fVec1[2];
	int IOTA0;
	float fVec2[4096];
	float fConst29;
	int iConst30;
	int iConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fConst35;
	float fConst36;
	FAUSTFLOAT fHslider0;
	float fRec3[2];
	float fConst37;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	float fRec5[2];
	int iRec7[2];
	float fConst38;
	float fRec6[2];
	float fRec1[3];
	float fConst39;
	float fRec0[5];
	float fConst40;
	FAUSTFLOAT fHslider2;
	float fRec10[2];
	FAUSTFLOAT fHslider3;
	float fRec11[2];
	float fRec9[3];
	float fRec8[5];
	
 public:
	mydsp() {
	}
	
	void metadata(Meta* m) { 
		m->declare("compile_options", "-lang cpp -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("filename", "vinyleffect.dsp");
		m->declare("filters.lib/bandpass0_bandstop1:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass0_bandstop1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass0_bandstop1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/bandpass:author", "Julius O. Smith III");
		m->declare("filters.lib/bandpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/bandpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/tf1sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2sb:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2sb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2sb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.6.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.8.1");
		m->declare("name", "vinyleffect");
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
		m->declare("signals.lib/version", "1.6.0");
	}

	virtual int getNumInputs() {
		return 1;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::tan(18849.557f / fConst0);
		fConst2 = std::sqrt(4.0f * mydsp_faustpower2_f(fConst0) * std::tan(267.03537f / fConst0) * fConst1);
		fConst3 = mydsp_faustpower2_f(fConst2);
		fConst4 = 1.0f / fConst0;
		fConst5 = mydsp_faustpower3_f(fConst4) * fConst3;
		fConst6 = fConst0 * fConst1;
		fConst7 = 2.0f * fConst6 - 0.5f * (fConst3 / fConst6);
		fConst8 = fConst7 * (8.0f / fConst0 + 2.0f * fConst5);
		fConst9 = mydsp_faustpower2_f(fConst7);
		fConst10 = mydsp_faustpower2_f(fConst4);
		fConst11 = mydsp_faustpower4_f(fConst4) * mydsp_faustpower4_f(fConst2);
		fConst12 = fConst11 + fConst10 * (4.0f * fConst9 + 8.0f * fConst3);
		fConst13 = fConst12 + (16.0f - fConst8);
		fConst14 = 4.0f * fConst5;
		fConst15 = 16.0f / fConst0;
		fConst16 = 4.0f * fConst11;
		fConst17 = fConst16 + fConst7 * (fConst15 - fConst14) + -64.0f;
		fConst18 = 6.0f * fConst11 + (96.0f - fConst10 * (8.0f * fConst9 + 16.0f * fConst3));
		fConst19 = fConst16 + fConst7 * (fConst14 - fConst15) + -64.0f;
		fConst20 = fConst8 + fConst12 + 16.0f;
		fConst21 = 1.0f / fConst20;
		fConst22 = 2.0f * (fConst7 / fConst0);
		fConst23 = fConst10 * fConst3;
		fConst24 = fConst23 + (4.0f - fConst22);
		fConst25 = 2.0f * fConst23 + -8.0f;
		fConst26 = fConst23 + fConst22 + 4.0f;
		fConst27 = 1.0f / fConst26;
		fConst28 = 5e+01f / fConst0;
		fConst29 = std::max<float>(0.0f, std::min<float>(2047.0f, 2e+03f * fConst0));
		iConst30 = int(fConst29);
		iConst31 = iConst30 + 1;
		fConst32 = std::floor(fConst29);
		fConst33 = fConst29 - fConst32;
		fConst34 = fConst32 + (1.0f - fConst29);
		fConst35 = 44.1f / fConst0;
		fConst36 = 1.0f - fConst35;
		fConst37 = 0.0015f * fConst0;
		fConst38 = 2.0535662e-08f / fConst0;
		fConst39 = 2.0f * (fConst7 / (fConst0 * fConst26));
		fConst40 = fConst10 * fConst9 / fConst20;
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.004f);
		fHslider1 = FAUSTFLOAT(0.4f);
		fHslider2 = FAUSTFLOAT(0.004f);
		fHslider3 = FAUSTFLOAT(0.4f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			fRec2[l1] = 0.0f;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec1[l2] = 0.0f;
		}
		IOTA0 = 0;
		for (int l3 = 0; l3 < 4096; l3 = l3 + 1) {
			fVec2[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec3[l4] = 0.0f;
		}
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fRec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec5[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 2; l7 = l7 + 1) {
			iRec7[l7] = 0;
		}
		for (int l8 = 0; l8 < 2; l8 = l8 + 1) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; l9 < 3; l9 = l9 + 1) {
			fRec1[l9] = 0.0f;
		}
		for (int l10 = 0; l10 < 5; l10 = l10 + 1) {
			fRec0[l10] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec10[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec11[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 3; l13 = l13 + 1) {
			fRec9[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 5; l14 = l14 + 1) {
			fRec8[l14] = 0.0f;
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
		ui_interface->openVerticalBox("vinyleffect");
		ui_interface->addHorizontalSlider("Left Pop Trigger", &fHslider0, FAUSTFLOAT(0.004f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Left Scratch Trigger", &fHslider1, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->addHorizontalSlider("Right Pop Trigger", &fHslider2, FAUSTFLOAT(0.004f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->addHorizontalSlider("Right Scratch Trigger", &fHslider3, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = fConst35 * float(fHslider0);
		float fSlow1 = fConst35 * float(fHslider1);
		float fSlow2 = fConst35 * float(fHslider2);
		float fSlow3 = fConst35 * float(fHslider3);
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 1;
			int iTemp0 = 1 - iVec0[1];
			float fTemp1 = ((iTemp0) ? 0.0f : fConst28 + fRec2[1]);
			fRec2[0] = fTemp1 - std::floor(fTemp1);
			float fTemp2 = mydsp_faustpower2_f(2.0f * fRec2[0] + -1.0f);
			fVec1[0] = fTemp2;
			float fTemp3 = float(iVec0[1]) * (fTemp2 - fVec1[1]);
			fVec2[IOTA0 & 4095] = fTemp3;
			float fTemp4 = fTemp3 - fConst34 * fVec2[(IOTA0 - iConst30) & 4095] - fConst33 * fVec2[(IOTA0 - iConst31) & 4095];
			fRec3[0] = fSlow0 + fConst36 * fRec3[1];
			fRec4[0] = fSlow1 + fConst36 * fRec4[1];
			float fTemp5 = ((iTemp0) ? 0.0f : fRec5[1] + fConst4 * float(input0[i0]));
			fRec5[0] = fTemp5 - std::floor(fTemp5);
			iRec7[0] = 1103515245 * iRec7[1] + 12345;
			fRec6[0] = fConst38 * float(iRec7[0]) + fConst36 * fRec6[1];
			float fTemp6 = 0.4f * fRec6[0];
			fRec1[0] = fTemp6 + 0.04f * fRec5[0] * fRec4[0] + fConst37 * fRec3[0] * fTemp4 - fConst27 * (fConst25 * fRec1[1] + fConst24 * fRec1[2]);
			fRec0[0] = fConst39 * (fRec1[0] - fRec1[2]) - fConst21 * (fConst19 * fRec0[1] + fConst18 * fRec0[2] + fConst17 * fRec0[3] + fConst13 * fRec0[4]);
			output0[i0] = FAUSTFLOAT(fConst40 * (4.0f * fRec0[0] - 8.0f * fRec0[2] + 4.0f * fRec0[4]));
			fRec10[0] = fSlow2 + fConst36 * fRec10[1];
			fRec11[0] = fSlow3 + fConst36 * fRec11[1];
			fRec9[0] = fTemp6 + 0.04f * fRec5[0] * fRec11[0] + fConst37 * fRec10[0] * fTemp4 - fConst27 * (fConst25 * fRec9[1] + fConst24 * fRec9[2]);
			fRec8[0] = fConst39 * (fRec9[0] - fRec9[2]) - fConst21 * (fConst19 * fRec8[1] + fConst18 * fRec8[2] + fConst17 * fRec8[3] + fConst13 * fRec8[4]);
			output1[i0] = FAUSTFLOAT(fConst40 * (4.0f * fRec8[0] - 8.0f * fRec8[2] + 4.0f * fRec8[4]));
			iVec0[1] = iVec0[0];
			fRec2[1] = fRec2[0];
			fVec1[1] = fVec1[0];
			IOTA0 = IOTA0 + 1;
			fRec3[1] = fRec3[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			iRec7[1] = iRec7[0];
			fRec6[1] = fRec6[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			for (int j0 = 4; j0 > 0; j0 = j0 - 1) {
				fRec0[j0] = fRec0[j0 - 1];
			}
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			for (int j1 = 4; j1 > 0; j1 = j1 - 1) {
				fRec8[j1] = fRec8[j1 - 1];
			}
		}
	}

};

#endif
