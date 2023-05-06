#include "klangerzeugung.h"

extern AudioOutputAnalog        dac44;    
extern AudioMixer4              mixer1; 
extern AudioSynthWaveform       waveform1;        
extern AudioSynthWaveform       waveform2;     
extern AudioSynthWaveform       waveform3; 
extern AudioFilterStateVariable filter1; 


Klangerzeugung::Klangerzeugung(){
   waveform1.begin(WAVEFORM_BANDLIMIT_SAWTOOTH);
   waveform1.amplitude(0.5);
   waveform1.frequency(32);

   waveform2.begin(WAVEFORM_SAWTOOTH);
   waveform2.amplitude(0.5);
   waveform2.frequency(32);

   waveform3.begin(WAVEFORM_SAWTOOTH);
   waveform3.amplitude(0.5);
   waveform3.frequency(32);

   filter1.frequency(200);
   filter1.resonance(4);
   filter1.octaveControl(4);
   
}

float Klangerzeugung::volume(){
   float lautstaerke = analogRead(potivolumePin);
  lautstaerke=map(lautstaerke,0,1023,0,1);

  return lautstaerke;
} 

int Klangerzeugung::frequenz(){
 int startfrq = 32;
 int freq=analogRead(potipitchPin);
 
 switch (octavebtn()){
  case 0:
   freq=map(freq,0,1023,startfrq,startfrq*2);
   break;
  case 1: 
   freq=map(freq,0,1023,startfrq*2,startfrq*4);
   break;
  case 2: 
   freq=map(freq,0,1023,startfrq*4,startfrq*8);
   break;
  case 3:
   freq=map(freq,0,1023,startfrq*8,startfrq*16);
   break;
  case 4:
   freq=map(freq,0,1023,startfrq*16,startfrq*32);
   break;
  case 5: 
   freq=map(freq,0,1023,startfrq*32,startfrq*64);
   break;
  case 6: 
   freq=map(freq,0,1023,startfrq*64,startfrq*128);
   break;
  case 7:
   freq=map(freq,0,1023,startfrq*128,startfrq*256);
   break;
 }
 return freq;
 }

int Klangerzeugung::octavebtn(){
  int octaveplus = digitalRead(buttonoctaveplusPin);
  static int btnStatus = 0;
  
  if(octaveplus==0){
     btnStatus ++;
     delay(250);
    if(btnStatus>=7){
      btnStatus =7;
      }
    }

  int octaveminus = digitalRead(buttonoctaveminusPin);
  
  if(octaveminus==0){
     btnStatus --;
     delay(250);
    if(btnStatus<=0){
      btnStatus =0;
      }
    }

  return btnStatus;
 }

float Klangerzeugung::detune(){

  float detuneamount = analogRead(potidetunePin);
   detuneamount = map(detuneamount,0,1023,0,3.5);
  
   return detuneamount;
}

int Klangerzeugung::cutoff(){
  int cutofffrq = analogRead(poticutoffPin);
   cutofffrq=map(cutofffrq,0,1023,0,7000);

  return cutofffrq;
}
