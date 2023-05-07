#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "Arduino.h"
#include <Audio.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>

AudioOutputAnalog dac44;
AudioMixer4 mixer1;
AudioSynthWaveform waveform1;
AudioSynthWaveform waveform2;
AudioSynthWaveform waveform3;
AudioFilterStateVariable filter1;

AudioConnection patchCord1(waveform1, 0, mixer1, 0);
AudioConnection patchCord2(waveform2, 0, mixer1, 1);
AudioConnection patchCord3(waveform3, 0, mixer1, 2);

AudioConnection patchCord4(mixer1, 0, filter1, 0);
AudioConnection patchCord5(filter1, 0, dac44, 0);

class synth
{
private:
public:
    synth(/* args */);
    ~synth();

    int frequenz;
    float volume;
    float detune;
};

synth::synth(/* args */)
{
}

synth::~synth()
{
}

#endif