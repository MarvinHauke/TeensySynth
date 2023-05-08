#ifndef _SOUNDGENERATION_H_
#define _SOUNDGENERATION_H_

#define buttonoctaveplusPin 18
#define buttonoctaveminusPin 17
#define buttonwaveformPin 16
#define potipitchPin 32
#define potivolumePin 31
#define potidetunePin 23
#define poticutoffPin 15
 
#include <Arduino.h>
#include <Audio.h>
#include <AudioStream.h>
// #include <Wire.h>
// #include <SPI.h>
// #include <SD.h>
// #include <SerialFlash.h> 


class Soundgeneration {
   
   private:

   public:
      Soundgeneration();
      
      int octavebtn();
      int frequenz();
      float volume();
      float detune();
      int cutoff();
 };


#endif