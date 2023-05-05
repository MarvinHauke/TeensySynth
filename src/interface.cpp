#include "interface.h"

    Interface::Interface(int statusLedGreen, int statusLedRed){
        Serial.println("hello from Interface");
    }

    void Interface::get_LedStatus(){
        Serial.println("hier könnte dein Ledstatus stehen");
    }