
//-------------------- Station colourCards------------------------------
#define S0 27
#define S1 28
#define S2 29
#define S3 30
#define sensorOut 56
#define rLED 34
#define gLED 35

#define progressLED1 31
#define progressLED2 32
#define progressLED3 33

//--------------------Station colourCards------------------------------
unsigned int red = 0;      // rgb values stored here
unsigned int green = 0;
unsigned int blue = 0;
int colourCardCounter = 0;  // sequencing
bool colourCardRemoved = true; // flag needed to exit for-loop after correct card is inserted

# define _red 10
# define _yellow 20
# define _blue 30
# define _nothing 0
char detectedColor = 0;

int ColourCardsFinished = 0;   // Variable that indicates that the game has been solved




bool colourCardIn() { // testing to see if card is in the slot with green triggerLED
  int r = 63;
  int g = 50;
  int b = 50;
  int tol = 50;
  if ((red >= (r - tol)) && (red <= (r + tol)) && (green >= (g - tol))
      && (green <= (g + tol)) && (blue >= (b - tol)) && (blue <= (b + tol))) {
    colourCardRemoved = true; // when card is removed, the loop is ready for testing again
    digitalWrite(rLED, HIGH);
    digitalWrite(gLED, LOW);
    Serial.println("Card slot empty!");
    return false;
  }
  else {
    return true;
  }
}

bool colourCardRed() {

  if ((red < green) && (green > blue)) {
    Serial.println("Red!");
    return true;
  }
  else {
    return false;
  }
}

bool colourCardYellow() {
  if ((red > green) && (green < blue)) {
    Serial.println("Yellow!");
    return true;
  }
  else {
    return false;
  }
}

bool colourCardBlue() {
  if ((red > green) && (green > blue)) {
    Serial.println("Blue!");
    return true;
  }
  else {
    return false;
  }
}


void colourSense() {
  // Setting RED photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading and saving
  red = pulseIn(sensorOut, LOW);
  Serial.print("R = ");
  Serial.print(red);
  Serial.print("  ");
  delay(10);

  // Setting GREEN photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading and saving
  green = pulseIn(sensorOut, LOW);
  Serial.print("G = ");
  Serial.print(green);
  Serial.print("  ");
  delay(10);

  // Setting BLUE photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading and saving
  blue = pulseIn(sensorOut, LOW);
  Serial.print("B = ");
  Serial.print(blue);
  Serial.println("  ");
  delay(10);

}


/* Main Method of Colour Cards Game

*/
void colourCards() {
  switch (colourCardCounter) {
    case 0:
      digitalWrite(progressLED1, LOW);
      digitalWrite(progressLED2, LOW);
      digitalWrite(progressLED3, LOW);
      break;
    case 1:
      digitalWrite(progressLED1, HIGH);
      break;
    case 2:
      digitalWrite(progressLED2, HIGH);
      break;
    case 3:
      digitalWrite(progressLED3, HIGH);
      break;
  }


  colourSense();
  detectedColor = _nothing;

  // Reading cards, comparing rgb values
  if (colourCardIn()) {

    for (int n = 1; n <= 10; n++) {
      colourSense();
      if (colourCardRed()) {
        detectedColor = _red;
      }
      if (colourCardYellow()) {
        detectedColor = _yellow;
      }
      if (colourCardBlue()) {
        detectedColor = _blue;
      }
    }


  }


  if (colourCardIn() && colourCardRemoved) {
    for (int i = 0; i < 3; i++) { // takes the third value
      colourSense();
    }
    if (colourCardCounter == 0 && detectedColor == _red) {
      colourCardCounter = 1;
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, HIGH);
      colourCardRemoved = false; // this prevents the loop from comparing the
      //current red card in the slot with colourCardCounter = 1;
      // = true will trigger when card is removed in colourCardIn();
      Serial.println("Card is Red!");
    }
    else if (colourCardCounter == 1 && detectedColor == _yellow) {
      colourCardCounter = 2;
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, HIGH);
      colourCardRemoved = false;
      Serial.println("Card is Yellow!");
    }
    else if (colourCardCounter == 2 && detectedColor == _blue) {
      // COLOURUNLOCKED!
      colourCardCounter = 3;
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, HIGH);
      colourCardRemoved = false;
      Serial.println("Card is Blue!");
      // Shut down colour sensor
      digitalWrite(S0, LOW);
      digitalWrite(S1, LOW);

      ColourCardsFinished = 1;
      digitalWrite(progressLED3, HIGH);
      // visual and/or audio cue

      // lock this station and unlock next station/prize

    }
    else { // What happens when the card is inserted in the wrong sequence
      colourCardCounter = 0; // here we start over
      // visual and/or audio cue
      for (int i = 0; i < 3; i++) { // blinks five times
        digitalWrite(rLED, LOW);
        digitalWrite(gLED, LOW);
        delay(300);
        digitalWrite(rLED, HIGH);
        delay(300);
      }
      colourCardRemoved = false;
      digitalWrite(rLED, HIGH);
      digitalWrite(gLED, LOW);
    }
  }
}

void ColourCardsPinSetup() {
  // Colour Sensor, Progress LED, red/green LED
  for (int i = 27; i <= 35; i++) {
    pinMode(i, OUTPUT);
  }
  // Colour Sensor
  pinMode(56, INPUT);


  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  // Setting initial values for LEDs
  digitalWrite(rLED, HIGH);
  digitalWrite(gLED, LOW);
}
