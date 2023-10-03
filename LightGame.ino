int targetIntensity;
int buzzer = 16;
int sensor = 36;
int currentIntensity = 0;

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

  // check if 10s has passed
  Serial.print("Time: ");
  myTime = millis();
  Serial.println(myTime); // prints time since program started

  // read light intensity at sensor
  currentIntensity = analogRead(sensor);
  Serial.printIn(currentIntensity);

  // compare light intensity read with targeted intensity
  

  // if number gets closer, buzzer plays higher pitch

  // if number gets further, buzzer plays lower pitch

  // if win, play win melody
  

  // if lose, play loser melody
  if (myTime > 10000) {
    playLoserMelody();
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