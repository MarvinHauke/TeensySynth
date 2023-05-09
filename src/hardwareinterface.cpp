#include "hardwareinterface.h"

Soundgeneration volumewert;


HardwareInterface::HardwareInterface(){
  

  pinMode(ledrotPin, OUTPUT);
  pinMode(ledgruenPin, OUTPUT);
}

void HardwareInterface::ledVolume (){
    if(volumewert.volume() <= 0.9){
      analogWrite(ledgruenPin, 200);
      analogWrite(ledrotPin, 0);
    }

    else if(volumewert.volume() > 0.9){
      analogWrite(ledrotPin, 200);
      analogWrite(ledgruenPin, 0);
    }
}
