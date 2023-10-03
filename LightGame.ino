int targetIntensity;
int buzzer = 16;
int sensor = 36;
int myTime = 0;
int currentIntensity = 0; // because i need to collect the data
int diffIntensity = 0; // because i have no idea what the value is yet
int pitch;
bool gameEnded = false;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  randomSeed(analogRead(0));

  // generate random number
  targetIntensity = random(4096); // print a random number from 0 to 4095
  Serial.println("The target intensity is..."); 
  Serial.println(targetIntensity); 

  // play simple melody
  playStartMelody();

}

void loop() {

  if (!gameEnded){
    // check if 10s has passed
    Serial.print("Stopwatch: ");
    myTime = millis();
    Serial.println(myTime); // prints time since program started

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
    if (myTime <= 10000 && currentIntensity == targetIntensity){
      playWinMelody();
      gameEnded = true;
      Serial.println("You win!");
      return;
    }

    // if lose, play loser melody
    if (myTime > 10000) {
      playLoserMelody();
      gameEnded = true;
      Serial.println("You lose!");
      return;
    }
  }

  // press key to restart



}

void playStartMelody(){
  // TODO
}

void playWinMelody(){

}

void playLoserMelody(){

}

