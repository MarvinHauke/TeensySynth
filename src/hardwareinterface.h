#ifndef _HARDWAREINTERFACE_H_
#define _HARDWAREINTERFACE_H_

#define buttonoctaveplusPin 18
#define buttonoctaveminusPin 17
#define buttonwaveformPin 16
#define potipitchPin 32
#define potivolumePin 31
#define potidetunePin 23
#define poticutoffPin 15

#include "Arduino.h"

class Hardwareinterface
{
private:
    /* data */
public:
    Hardwareinterface(/* args */);
    ~Hardwareinterface();
};

int octavebtn();

int waveformbtn();
int cutoff();

#endif