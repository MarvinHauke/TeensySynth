#include <Arduino.h>
#include <Audio.h>
#include <MIDIUSB.h>
#include "hardwareinterface.h"
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

HardwareInterface ledVolume1;

//GOLBAL VARIABLES
const byte BUFFER = 8;      // Size of the Keyboardbuffer
const float noteFreqs[128] = {    //Array von Noten-Werten
8.176, 8.662, 9.177, 9.723, 10.301, 10.913, 11.562, 12.25, 12.978, 13.75, 14.568, 15.434, 16.352, 17.324, 18.354, 19.445, 20.602, 21.827, 23.125, 24.5, 25.957, 27.5, 29.135, 30.868, 32.703, 34.648, 36.708, 38.891, 41.203, 43.654, 46.249, 48.999, 51.913, 55, 58.27, 61.735, 65.406, 69.296, 73.416, 77.782, 82.407, 87.307, 92.499, 97.999, 103.826, 110, 116.541, 123.471, 130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220, 233.082, 246.942, 261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440, 466.164, 493.883, 523.251, 554.365, 587.33, 622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880, 932.328, 987.767, 1046.502, 1108.731, 1174.659, 1244.508, 1318.51, 1396.913, 1479.978, 1567.982, 1661.219, 1760, 1864.655, 1975.533, 2093.005, 2217.461, 2349.318, 2489.016, 2637.02, 2793.826, 2959.955, 3135.963, 3322.438, 3520, 3729.31, 3951.066, 4186.009, 4434.922, 4698.636, 4978.032, 5274.041, 5587.652, 5919.911, 6271.927, 6644.875, 7040, 7458.62, 7902.133, 8372.018, 8869.844, 9397.273, 9956.063, 10548.08, 11175.3, 11839.82, 12543.85};
byte globalNote = 0;
byte globalVelocity = 0;

const float DIV127 = (1.0 / 127.0);



void midiCC (byte channel, byte control, byte value);
void myNoteOn (byte channel, byte note, byte velocity);
void myNoteOff (byte channel, byte note, byte velocity);
void keyBuff (byte note, bool playNote);
void oscPlay(byte note);
void oscStop();

void setup() {
  Serial.begin(57600);
  AudioMemory(20);

  usbMIDI.setHandleControlChange(midiCC);
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);


  pinMode(potipitchPin, INPUT);
  pinMode(potivolumePin, INPUT);
  pinMode(potidetunePin, INPUT);
  pinMode(poticutoffPin, INPUT);
  pinMode(buttonoctaveplusPin, INPUT_PULLUP);
  pinMode(buttonoctaveminusPin, INPUT_PULLUP);
  pinMode(ledrotPin, OUTPUT);
  pinMode(ledgruenPin, OUTPUT);

  waveform1.begin(WAVEFORM_BANDLIMIT_SAWTOOTH);
  waveform1.amplitude(0.5);
  waveform1.frequency(32);

  waveform2.begin(WAVEFORM_SAWTOOTH);
  waveform2.amplitude(0.5);
  waveform2.frequency(32);

  waveform3.begin(WAVEFORM_SAWTOOTH);
  waveform3.amplitude(0.5);
  waveform3.frequency(32);

  filter1.frequency(200);
  filter1.resonance(4);
  filter1.octaveControl(4);

  
}

void loop() {

  usbMIDI.read();

  // waveform1.frequency(frequenz());
  // waveform1.amplitude(volume());

  // waveform2.frequency(frequenz()+detune());
  // waveform2.amplitude(volume());

  // waveform3.frequency(frequenz()-detune());
  // waveform3.amplitude(volume());

  filter1.frequency(cutoff());

  ledVolume1.ledVolume();
}

void midiCC (byte channel, byte control, byte value){   //channel = 1-16; control = 0-127; value = 0-127
    mixer1.gain(0, (float)value / 127);
    mixer1.gain(1, (float)value / 127);
    mixer1.gain(2, (float)value / 127);
}

void myNoteOn (byte channel, byte note, byte velocity){  //channel = 1-16; note = 0-127; velocity = 0-127
    if (note>23 && note <108){                           //nicht unter C0 gehen und nicht über zu hohe Note gehen
      globalNote = note;                                 //wenn die Note in dem Bereich spielt, wird die 'note' einer globalen Variable übergeben
      globalVelocity = velocity;
      keyBuff(note,true);
    }
}

void myNoteOff (byte channel, byte note, byte velocity){  
    if (note>23 && note <108){                           
      keyBuff(note,false);
    }
}


void keyBuff(byte note, bool playNote) {
  static byte buff[BUFFER];
  static byte buffSize = 0;

  // Add Note
  if (playNote == true && (buffSize < BUFFER) ) {
    oscPlay(note);
    buff[buffSize] = note;
    buffSize++;
    return;
  }

  // Remove Note
  else if (playNote == false && buffSize != 0) {
    for (byte found = 0; found < buffSize; found++) {
      if (buff[found] == note) {
        for (byte gap = found; gap < (buffSize - 1); gap++) {
          buff[gap] = buff[gap + 1];
        }
        buffSize--;
        buff[buffSize] = 255;
        if (buffSize != 0) {
          oscPlay(buff[buffSize - 1]);
          return;
        }
        else {
          oscStop();
          return;
        }
      }
    }
  }
}

void oscPlay(byte note){
    waveform1.frequency(noteFreqs[note]);
    waveform2.frequency(noteFreqs[note]);
    waveform3.frequency(noteFreqs[note]);
    float velo = (globalVelocity * DIV127);
    waveform1.amplitude(velo);
    waveform2.amplitude(velo);
    waveform3.amplitude(velo);
}

void oscStop(){
  waveform1.amplitude(0.0);
  waveform2.amplitude(0.0);
  waveform3.amplitude(0.0);
}