#ifndef _HARDWAREINTERFACE_H_
#define _HARDWAREINTERFACE_H_

#include <Arduino.h>
#include "synth.h" 

#define ledrotPin 30
#define ledgruenPin 29 

class HardwareInterface {
   private:
     
   public:
      HardwareInterface();
      void ledVolume();
 };
 
#endif