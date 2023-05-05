#include "midiInterface.h"

// TODO: add audiomixer instanz to implement midiCC korrekt or
//  seperate it to another file/class
class MidiInterface
{
private:
    int bla = 0;

public:
    MidiInterface()
    {
    }
    void midiCC(byte channel, byte control, byte value)
    {
        mixer1.gain(0, (float)value / 127);
        mixer1.gain(1, (float)value / 127);
        mixer1.gain(2, (float)value / 127);
    }
};