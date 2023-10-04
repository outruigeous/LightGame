#include "pitches.h"

int targetIntensity;
int buzzer = 16;
int sensor = 36;
int startTime = 0;
int endTime;
int currentIntensity = 0; // because i need to collect the data
int diffIntensity = 0; // because i have no idea what the value is yet
int pitch;
int startMelody[] = {
 0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G6
};
int startNoteDuration[] = {
 2, 2, 2, 2, 1
};

int winMelody[] = {
 0, NOTE_F4, NOTE_AS4, NOTE_D5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_D5, NOTE_AS4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_AS4
};
int winNoteDuration[] = {
  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
};
int loserMelody[] = {
  0, NOTE_C6, NOTE_B5, NOTE_AS5, NOTE_A5
};

int loserNoteDuration[] = {
  4, 4, 4, 4, 4
};
bool gameEnded = false;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  setupGame();

}

void loop() {

  if (!gameEnded){
    // check if 10s has passed
    endTime = startTime + 10000;
   

    // read light intensity at sensor
    currentIntensity = analogRead(sensor);
    Serial.print("Current Intensity: ");
    Serial.println(currentIntensity);


    // if number gets closer, buzzer plays higher pitch
    // if number gets further, buzzer plays lower pitch
    diffIntensity = abs(targetIntensity - currentIntensity);
    pitch = map(diffIntensity,0,4095,2000,31);
    tone(buzzer, pitch);

    // if win, play win melody
    if (millis() < endTime && diffIntensity < 50){
      playWinMelody();
      gameEnded = true;
      Serial.println("You win!");
      return;
    }

    // if lose, play loser melody
    if (millis() > endTime) {
      playLoserMelody();
      gameEnded = true;
      Serial.println("You lose!");
      return;
    }
  }

  // press key to restart
  if (gameEnded == true && Serial.available() > 0) {
    // read the incoming byte:
    Serial.readString();
    setupGame();
  }


}

void playStartMelody(){
  int melodyLength = sizeof(startMelody);

  for (int thisNote = 0; thisNote < 5; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / startNoteDuration[thisNote];

    tone(buzzer, startMelody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzzer);
  }

}

void playWinMelody(){
  int melodyLength = sizeof(startMelody);

  for (int thisNote = 0; thisNote < 13; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / winNoteDuration[thisNote];

    tone(buzzer, winMelody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzzer);
  }
}

void playLoserMelody(){
  int melodyLength = sizeof(startMelody);

  for (int thisNote = 0; thisNote < 5; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / loserNoteDuration[thisNote];

    tone(buzzer, loserMelody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(buzzer);
  }
}

void setupGame(){
  gameEnded = false;
  randomSeed(analogRead(sensor));

  // generate random number
  targetIntensity = random(4096); // print a random number from 0 to 4095
  Serial.println("The target intensity is..."); 
  Serial.println(targetIntensity); 

  // play simple melody
  playStartMelody();

  // record timestamp after StartMelody is played
  startTime = millis();
}