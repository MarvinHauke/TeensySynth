#include "hardwareinterface.h"

Hardwareinterface::Hardwareinterface(/* args */)
{
    pinMode(potipitchPin, INPUT);
    pinMode(potivolumePin, INPUT);
    pinMode(potidetunePin, INPUT);
    pinMode(poticutoffPin, INPUT);
    pinMode(buttonoctaveplusPin, INPUT_PULLUP);
    pinMode(buttonoctaveminusPin, INPUT_PULLUP);
    pinMode(buttonwaveformPin, INPUT_PULLUP);
}

Hardwareinterface::~Hardwareinterface()
{
}
