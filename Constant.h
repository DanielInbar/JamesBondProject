#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "pitches.h"

namespace Constants {

  // const int BUZZER_PIN = 9;

  // const int GREEN_LED_PIN = 5;
  // const int RED_LED_PIN = 6;

  // const int SELECT_BUTTON_PIN = 8;
  // const int RESET_BUTTON_PIN = 7;

  // const int POTENTIOMETER_PIN = A0;


  const int erikaMelody[] = {
      NOTE_C4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_A4, NOTE_A4,

      NOTE_C5, NOTE_C5, REST,
      NOTE_B4, NOTE_A4, REST,

      NOTE_G4, NOTE_A5, NOTE_B5, REST,

      NOTE_C5,
      NOTE_B4, NOTE_A4, REST
    };

  const int erikaDurations[] = {
    2, 8, 3, 3, 3, 3, 3,

    3, 3, 4,
    8, 8, 4,

    3, 3, 3, 2,

    2,
    8, 8, 1
  };

  const int erikaSizeOfDurations = sizeof(erikaDurations); 

  const int morningMoodMelody[] = {
    NOTE_B6, NOTE_GS5, NOTE_FS5,
    NOTE_E5, NOTE_FS5, NOTE_GS5,
    NOTE_B6, NOTE_GS5, NOTE_FS5,
    NOTE_E5, NOTE_FS5, NOTE_GS5, NOTE_FS5, NOTE_GS5,
    NOTE_B6, NOTE_GS5, NOTE_B6,
    NOTE_C6, NOTE_GS5, NOTE_C6,
    NOTE_B6, NOTE_GS5, NOTE_FS5, REST

  };

  const int morningMoodDurations[] = {
    3, 3, 3,
    3, 3, 3,
    3, 3, 3,
    6, 9, 6, 9, 6,
    3, 3, 3,
    3, 3, 3,
    3, 3, 3, 2
  };

  const int morningMoodSizeOfDurations = sizeof(morningMoodDurations);
}


#endif