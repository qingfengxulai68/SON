#include "MyDsp.h"

// définition des macro
#define AUDIO_OUTPUTS 2
#define MULT_16 32767


// déclaration du constructeur
MyDsp::MyDsp() : 
// on instance ces trucs pour pouvoir les utiliser après
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
additive(AUDIO_SAMPLE_RATE_EXACT),  // sine prend en entrée le taux d'échantillonnage
echo_droit(AUDIO_SAMPLE_RATE_EXACT,6000),
echo_gauche(AUDIO_SAMPLE_RATE_EXACT,4000)
{ 
  // paramétrage de écho
  echo_droit.setDel(8000); // retard
  echo_droit.setFeedback(0.1);
  echo_gauche.setDel(2000); // retard
  echo_gauche.setFeedback(0.5);
  // paramétrage de delta et vol
  delta = 1/(AUDIO_SAMPLE_RATE_EXACT*5);
  vol = delta;
}

// set sine wave frequency
void MyDsp::setFreq(float freq){
  additive.setFrequency(freq);
}

void MyDsp::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  float memory = additive.tick();
  outBlock[0] = allocate();
  outBlock[1] = allocate();
    for (int i=0; i< AUDIO_BLOCK_SAMPLES; i++) {
      if(vol >= 1 || vol <= 0) {
        delta = -delta; 
        vol = vol + delta;
        float currentSample = echo_droit.tick(memory)*0.5*(vol*vol);
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[0]->data[i] = val;
      }
      float currentSample = echo_gauche.tick(memory)*0.5;
      currentSample = max(-1,min(1,currentSample));
      int16_t val = currentSample*MULT_16;
      outBlock[1]->data[i] = val;
      }
    transmit(outBlock[0], 0);
    transmit(outBlock[1], 1);
    release(outBlock[0]);
    release(outBlock[1]);
}




