int randNumber;
int buzzer = 16;
int sensor = 36;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  randomSeed(analogRead(0));
}

void loop() {



  // generate random number
  randNumber = random(4096); // print a random number from 0 to 4095
  Serial.println(randNumber);

  // play simple melody

  // start 10s countdown

  // read light intensity at sensor

  // compare light intensity read with targeted intensity

  // if number gets closer, buzzer plays higher pitch

  // if number gets further, buzzer plays lower pitch

  // if win, play win melody

  // if lose, play loser melody

  // press key to restart






}