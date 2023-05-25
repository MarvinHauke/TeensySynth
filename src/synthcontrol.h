#ifndef _SYNTHCONTROL_H_
#define _SYNTHCONTROL_H_
 
#include <Arduino.h>
// #include <Audio.h>
// #include <AudioStream.h>

#define buttonoctaveplusPin 18
#define buttonoctaveminusPin 17
#define buttonwaveformPin 16


#define potivolumePin 31
#define potidetunePin 23
#define poticutoffPin 15
#define potiresonancePin 32

class Synthcontrol {
   
   private:

   public:
      Synthcontrol();
 
      float volume();
      float detune();
      int cutoff();
      float resonanceQ();

      // int octavebtn();
      // int frequenz();
 };


#endif