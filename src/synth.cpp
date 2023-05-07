#include "synth.h"

int octavebtn()
{
  int octaveplus = digitalRead(buttonoctaveplusPin);
  static int btnStatus = 0;

  if (octaveplus == 0)
  {
    btnStatus++;
    delay(250);
    if (btnStatus >= 7)
    {
      btnStatus = 7;
    }
  }

  int octaveminus = digitalRead(buttonoctaveminusPin);

  if (octaveminus == 0)
  {
    btnStatus--;
    delay(250);
    if (btnStatus <= 0)
    {
      btnStatus = 0;
    }
  }

  return btnStatus;
}

float detune()
{

  float detuneamount = analogRead(potidetunePin);
  detuneamount = map(detuneamount, 0, 1023, 0, 3.5);

  return detuneamount;
}

int cutoff()
{
  int cutofffrq = analogRead(poticutoffPin);
  cutofffrq = map(cutofffrq, 0, 1023, 0, 7000);

  return cutofffrq;
}

// int waveformbtn(){
//   int waveformplus = digitalRead(buttonwaveformPin);
//   static int btnstatus = 0;

//   if (waveformplus == 0){
//    btnstatus ++;
//    delay (250);
//     if (waveformplus >4){
//       btnstatus =0;
//     }
//   }
