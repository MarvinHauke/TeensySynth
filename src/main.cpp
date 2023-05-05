#include <Arduino.h>
#include <Audio.h>
#include <MIDIUSB.h>

#include "synth.h"
// #include "calvinmidi.h"

        
AudioOutputAnalog        dac44;    
AudioMixer4              mixer1;          
AudioSynthWaveform       waveform1;        
AudioSynthWaveform       waveform2;     
AudioSynthWaveform       waveform3; 
AudioFilterStateVariable filter1;          

AudioConnection          patchCord1(waveform1, 0, mixer1, 0);
AudioConnection          patchCord2(waveform2, 0, mixer1, 1);
AudioConnection          patchCord3(waveform3, 0, mixer1, 2);

AudioConnection          patchCord4(mixer1, 0, filter1, 0);
AudioConnection          patchCord5(filter1, 0, dac44, 0);

void midiCC (byte channel, byte control, byte value);

void setup() {
  Serial.begin(57600);
  AudioMemory(20);
  usbMIDI.setHandleControlChange(midiCC);

  pinMode(potipitchPin, INPUT);
  pinMode(potivolumePin, INPUT);
  pinMode(potidetunePin, INPUT);
  pinMode(poticutoffPin, INPUT);
  pinMode(buttonoctaveplusPin, INPUT_PULLUP);
  pinMode(buttonoctaveminusPin, INPUT_PULLUP);
  pinMode(buttonwaveformPin, INPUT_PULLUP);

  waveform1.begin(WAVEFORM_BANDLIMIT_SAWTOOTH);
  waveform1.amplitude(1);
  waveform1.frequency(32);

  waveform2.begin(WAVEFORM_SAWTOOTH);
  waveform2.amplitude(1);
  waveform2.frequency(32);

  waveform3.begin(WAVEFORM_SAWTOOTH);
  waveform3.amplitude(1);
  waveform3.frequency(32);

  filter1.frequency(200);
  filter1.resonance(4);
  filter1.octaveControl(4);

}

void loop() {
  usbMIDI.read();

  waveform1.frequency(frequenz());
  waveform1.amplitude(volume());

  waveform2.frequency(frequenz()+detune());
  waveform2.amplitude(volume());

  waveform3.frequency(frequenz()-detune());
  waveform3.amplitude(volume());

  filter1.frequency(cutoff());

  Serial.println(volume());
}

void midiCC (byte channel, byte control, byte value){ 
    mixer1.gain(0, (float)value / 127);
    mixer1.gain(1, (float)value / 127);
    mixer1.gain(2, (float)value / 127);
}