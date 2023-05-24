#include "synthcontrol.h"

Soundgeneration::Soundgeneration(){ 
  
  pinMode(potivolumePin, INPUT);
  pinMode(potidetunePin, INPUT);
  pinMode(poticutoffPin, INPUT);
  pinMode(potiresonancePin, INPUT);
  pinMode(buttonoctaveplusPin, INPUT_PULLUP); 
  pinMode(buttonoctaveminusPin, INPUT_PULLUP);
}

float Soundgeneration::volume(){
   float lautstaerke = analogRead(potivolumePin);
  lautstaerke=map(lautstaerke,0,1023,0,1);

  return lautstaerke;
} 


float Soundgeneration::detune(){

  float detuneamount = analogRead(potidetunePin);
   detuneamount = map(detuneamount,0,1023,0,3.5);
  
   return detuneamount;
}

int Soundgeneration::cutoff(){
  int cutofffrq = analogRead(poticutoffPin);
   cutofffrq=map(cutofffrq,0,1023,0,7000);

  return cutofffrq;
}

float Soundgeneration::resonanceQ(){
  float resoqwert = analogRead(potiresonancePin);
   resoqwert=map(resoqwert,0,1023,0.7,5.0);

  return resoqwert;
}


// int Soundgeneration::frequenz(){
//  int startfrq = 32;
//  int freq=analogRead(potipitchPin);
 
//  switch (octavebtn()){
//   case 0:
//    freq=map(freq,0,1023,startfrq,startfrq*2);
//    break;
//   case 1: 
//    freq=map(freq,0,1023,startfrq*2,startfrq*4);
//    break;
//   case 2: 
//    freq=map(freq,0,1023,startfrq*4,startfrq*8);
//    break;
//   case 3:
//    freq=map(freq,0,1023,startfrq*8,startfrq*16);
//    break;
//   case 4:
//    freq=map(freq,0,1023,startfrq*16,startfrq*32);
//    break;
//   case 5: 
//    freq=map(freq,0,1023,startfrq*32,startfrq*64);
//    break;
//   case 6: 
//    freq=map(freq,0,1023,startfrq*64,startfrq*128);
//    break;
//   case 7:
//    freq=map(freq,0,1023,startfrq*128,startfrq*256);
//    break;
//  }
//  return freq;
//  }

// int Soundgeneration::octavebtn(){
//   int octaveplus = digitalRead(buttonoctaveplusPin);
//   static int btnStatus = 0;
  
//   if(octaveplus==0){
//      btnStatus ++;
//      delay(250);
//     if(btnStatus>=7){
//       btnStatus =7;
//       }
//     }

//   int octaveminus = digitalRead(buttonoctaveminusPin);
  
//   if(octaveminus==0){
//      btnStatus --;
//      delay(250);
//     if(btnStatus<=0){
//       btnStatus =0;
//       }
//     }

//   return btnStatus;
//  }