/*
  Play a melody.

  created 2020-06-11
  by Collin Mandris

  This code is modified from the Tone example code and is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone

  Guess the melody that I use.
*/

#include "Pitches.h"


void playMelody() {
  //the notes to play, using the defined values in Pitches.h
  int melody[] = {
    NOTE_C5,NOTE_D5,NOTE_E5,NOTE_FS5,NOTE_E5,NOTE_FS5,
    NOTE_G5,NOTE_D5,NOTE_B4,NOTE_D5,
    NOTE_C5,NOTE_B4,NOTE_A4,NOTE_B4,
    NOTE_G4,NOTE_G5
  };

  //the duration of each note to play (4 = quarter note, 8 = eighth note, etc.)
  int noteDurations[] = {
    24,24,24,24,24,24,
    12,24,12,24,
    12,24,12,24,
    8,12
  };

  //iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < (sizeof(melody)/sizeof(melody[0])); thisNote++) {

    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    toneAlt(melody[thisNote], noteDuration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
  }
}
