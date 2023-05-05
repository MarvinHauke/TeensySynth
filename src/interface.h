#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include <Arduino.h>

class Interface {
    private:
       int statusLedGreen;
       int statusLedRed;
    public:
       Interface(int statusLedGreen, int statusLedRed);
        void get_LedStatus();
};


#endif