#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Additive.h"
// #include "Sine.h"
#include "Echo.h"

// Déclaration de la classe MyDsp
class MyDsp : public AudioStream  // MyDsp hérite de AudioStream
{
  public: // méthode accessible
    MyDsp();  // constructeur
    ~MyDsp(); // destructeur
    
    virtual void update(void);
    void setFreq(float freq); // utilisable par crazy-sine.ino car public
    
  private:
    float vol, delta;
    Additive additive;
    // Sine sine;  // objet de Sine.h
    Echo echo_droit;  // objet de Echo.h
    Echo echo_gauche;
};

#endif
