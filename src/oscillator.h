#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_

#include <Audio.h>
#include "soundgeneration.h"

class Oscillator : public Soundgeneration {
private:
    /* data */
public:
    Oscillator(int startFreq = 32, float startAmp = 0.5);
};




#endif