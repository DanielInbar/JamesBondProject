#include "Melodies.h"

// actual definitions (copy your arrays here — exactly once)

int erikaMelody[] = {
  262, 294, 330, 330, 330, 440, 440,
  523, 523, 0, 494, 440, 0,
  392, 880, 988, 0, 523, 494, 440, 0
};
int erikaDurations[] = {
  2,8,3,3,3,3,3, 3,3,4,8,8,4, 3,3,3,2,2,8,8,1
};
const int erikaLen = sizeof(erikaDurations) / sizeof(erikaDurations[0]);

int morningMoodMelody[] = {
  1976, 1661, 1480, 1318, 1480, 1661,
  1976, 1661, 1480, 1318, 1480, 1661, 1480, 1661,
  1976, 1661, 1976, 2093, 1661, 2093, 1976, 1661, 1480, 0
};
int morningMoodDurations[] = {
  3,3,3,3,3,3,3,3,3,6,9,6,9,6,3,3,3,3,3,3,3,3,3,2
};
const int morningMoodLen = sizeof(morningMoodDurations) / sizeof(morningMoodDurations[0]);
