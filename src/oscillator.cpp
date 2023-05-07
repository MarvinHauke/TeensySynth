#include "Oscillator.h"

Oscillator::Oscillator(int initFreq, float initAmp)
{
    waveform1.begin(WAVEFORM_BANDLIMIT_SAWTOOTH);
    waveform1.amplitude(initAmp);
    waveform1.frequency(initFreq);

    waveform2.begin(WAVEFORM_SAWTOOTH);
    waveform2.amplitude(initAmp);
    waveform2.frequency(initFreq);

    waveform3.begin(WAVEFORM_SAWTOOTH);
    waveform3.amplitude(initAmp);
    waveform3.frequency(initFreq);
}

Oscillator::~Oscillator()
{
}

float volume()
{
    float lautstaerke = analogRead(potivolumePin);
    lautstaerke = map(lautstaerke, 0, 1023, 0, 1);

    return lautstaerke;
}

int frequenz(int startFreq)
{
    int freq = analogRead(potipitchPin);

    switch (octavebtn())
    {
    case 0:
        freq = map(freq, 0, 1023, startFreq, startFreq * 2);
        break;
    case 1:
        freq = map(freq, 0, 1023, startFreq * 2, startFreq * 4);
        break;
    case 2:
        freq = map(freq, 0, 1023, startFreq * 4, startFreq * 8);
        break;
    case 3:
        freq = map(freq, 0, 1023, startFreq * 8, startFreq * 16);
        break;
    case 4:
        freq = map(freq, 0, 1023, startFreq * 16, startFreq * 32);
        break;
    case 5:
        freq = map(freq, 0, 1023, startFreq * 32, startFreq * 64);
        break;
    case 6:
        freq = map(freq, 0, 1023, startFreq * 64, startFreq * 128);
        break;
    case 7:
        freq = map(freq, 0, 1023, startFreq * 128, startFreq * 256);
        break;
    }
    return freq;
}
