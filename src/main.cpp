#include <Arduino.h>
#include <Audio.h>
#include <MIDIUSB.h>

#include "synth.h"
#include "hardwareinterface.h"
#include "oscillator.h"

void midiCC(byte channel, byte control, byte value)
{
  mixer1.gain(0, (float)value / 127);
  mixer1.gain(1, (float)value / 127);
  mixer1.gain(2, (float)value / 127);
}
void setup()
{
  Serial.begin(57600);
  AudioMemory(20);
  Hardwareinterface hardwareInterface;
  Oscillator osci1; // TODO implement Konstruktor correct
  // TODO:use a lambda function instead of midiCC()
  // usbMIDI.setHandleControlChange([]() {});
}

void loop()
{
  usbMIDI.read();

  // waveform1.frequency(frequenz());
  // waveform1.amplitude(volume());

  // waveform2.frequency(frequenz() + detune());
  // waveform2.amplitude(volume());

  // waveform3.frequency(frequenz() - detune());
  // waveform3.amplitude(volume());

  // filter1.frequency(cutoff());

  // Serial.println(volume());
}