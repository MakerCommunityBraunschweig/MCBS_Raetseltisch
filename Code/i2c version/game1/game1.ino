#include <Wire.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define rLED 6
#define gLED 7
#define sensorOut 8
#define progressLED1 9
#define progressLED2 10
#define progressLED3 11

//--------------------Station colourCards------------------------------
char output = 0;
int gamestatus = 0;
unsigned int red = 0;      // rgb values stored here
unsigned int green = 0;
unsigned int blue = 0;
bool colourCardRemoved = true; // flag needed to exit for-loop after correct card is inserted

# define _red 1
# define _yellow 3
# define _blue 2
# define _nothing 0


void setup() {
  Serial.begin(9600);
  Wire.begin(1);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(progressLED1, OUTPUT);
  pinMode(progressLED2, OUTPUT);
  pinMode(progressLED3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  // Setting initial values for LEDs
  digitalWrite(rLED, HIGH);
  digitalWrite(gLED, LOW);
}

void loop() {
  colourSense();
  switch (gamestatus) {

    case 1:
      switch (cardcolour()) {
        case 0:
          break;

        case _red:
          gamestatus++;
          updateProgressLed();
          break;

        default:
          output = 'f';
      }
      break;

    case 2:
      switch (cardcolour()) {
        case 0:
          break;

        case _blue:
          gamestatus++;
          updateProgressLed();
          break;

        default:
          output = 'f';
      }
      break;

    case 3:
      switch (cardcolour()) {
        case 0:
          break;

        case _yellow:
          output = 's';
          updateProgressLed();
          break;

        default:
          output = 'f';
      }
      break;
  }
  waitForRemove();
}
