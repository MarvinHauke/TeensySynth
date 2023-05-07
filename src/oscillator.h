#ifndef _OCILLATOR_H_
#define _OCILLATOR_H_
#include <Audio.h>
#include "synth.h"

class Oscillator : public Synth
{
private:
    /* data */
public:
    Oscillator(int startFreq = 32, float startAmp = 0.5);
    ~Oscillator();
};

#endif // !_OCILLATOR_H_
