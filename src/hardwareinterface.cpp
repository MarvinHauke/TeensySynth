#include "hardwareinterface.h"


HardwareInterface::HardwareInterface(){
}

void HardwareInterface::ledVolume (){
    if(volume() <= 0.9){
      analogWrite(ledgruenPin, 200);
      analogWrite(ledrotPin, 0);
    }

    if(volume() > 0.9){
      analogWrite(ledrotPin, 200);
      analogWrite(ledgruenPin, 0);
    }
}
