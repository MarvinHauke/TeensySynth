#include "midisteuerung.h"

// void midiCC (byte channel, byte control, byte value){   //channel = 1-16; control = 0-127; value = 0-127
//     mixer1.gain(0, (float)value / 127);
//     mixer1.gain(1, (float)value / 127);
//     mixer1.gain(2, (float)value / 127);
// }

// void myNoteOn (byte channel, byte note, byte velocity){  //channel = 1-16; note = 0-127; velocity = 0-127
//     if (note>23 && note <108){                           //nicht unter C0 gehen und nicht über zu hohe Note gehen
//       globalNote = note;                                 //wenn die Note in dem Bereich spielt, wird die 'note' einer globalen Variable übergeben
//       globalVelocity = velocity;
//       keyBuff(note,true);
//     }
// }

// void myNoteOff (byte channel, byte note, byte velocity){  
//     if (note>23 && note <108){                           
//       keyBuff(note,false);
//     }
// }


// void keyBuff(byte note, bool playNote) {
//   static byte buff[BUFFER];
//   static byte buffSize = 0;

//   // Add Note
//   if (playNote == true && (buffSize < BUFFER) ) {
//     oscPlay(note);
//     buff[buffSize] = note;
//     buffSize++;
//     return;
//   }

//   // Remove Note
//   else if (playNote == false && buffSize != 0) {
//     for (byte found = 0; found < buffSize; found++) {
//       if (buff[found] == note) {
//         for (byte gap = found; gap < (buffSize - 1); gap++) {
//           buff[gap] = buff[gap + 1];
//         }
//         buffSize--;
//         buff[buffSize] = 255;
//         if (buffSize != 0) {
//           oscPlay(buff[buffSize - 1]);
//           return;
//         }
//         else {
//           oscStop();
//           return;
//         }
//       }
//     }
//   }
// }

// void oscPlay(byte note){
//     waveform1.frequency(noteFreqs[note]);
//     waveform2.frequency(noteFreqs[note]);
//     waveform3.frequency(noteFreqs[note]);
//     float velo = (globalVelocity * DIV127);
//     waveform1.amplitude(velo);
//     waveform2.amplitude(velo);
//     waveform3.amplitude(velo);
// }

// void oscStop(){
//   waveform1.amplitude(0.0);
//   waveform2.amplitude(0.0);
//   waveform3.amplitude(0.0);
// }
