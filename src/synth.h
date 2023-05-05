#ifndef _SYNTH_H_
#define _SYNTH_H_

#define buttonoctaveplusPin 18
#define buttonoctaveminusPin 17
#define buttonwaveformPin 16
#define potipitchPin 32
#define potivolumePin 31
#define potidetunePin 23
#define poticutoffPin 15
 

#include <Audio.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h>


int octavebtn();
// int waveformbtn();
int frequenz();
float volume();
float detune();
int cutoff();



#endif