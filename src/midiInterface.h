#ifndef _MIDIINTERFACE_H_
#define _MIDIINTERFACE_H_

#include <Audio.h>
#include "synth.h"
#include <MIDIUSB.h>

class MidiInterface
{
private:
    int bla;

public:
    MidiInterface();
    void midiCC(byte channel, byte control, byte value);
};

#endif
