#ifndef Buzzer_h
#define Buzzer_h

class Buzzer {
  private:
    int pin;
    int* melody;
    int* durations;
    int size;
    int currentNote;
    unsigned long noteStartMillis;
    bool playing;
  public:
    Buzzer(int pin);
    init();
    playMelody(int melody[], int durations[], int sizeOfDurations);
    stopMelody();
    update();  
    bool isPlaying(); 
};

#endif