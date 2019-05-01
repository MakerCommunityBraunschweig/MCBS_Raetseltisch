#include <Wire.h>

#define button1 2
#define button2 3
#define button3 4
#define button4 5
const int button_Pins[5] = {0, button1, button2, button3, button4}; //makes use easier on other tabs

#define led1 6
#define led2 7
#define led3 8
#define led4 9
const int LED_Pins[5] = {0, led1, led2, led3, led4};  //makes use easier on other tabs
int LED_Status[5] = {0, 0, 0, 0, 0};

char output = 0;
int gamestatus = 0;
int pressedButton = 0;
int lastPressedButton = 0;
const int answers[] = {0, 3, 1, 2, 3};

void setup() {
  Serial.begin(9600);
  Wire.begin(2);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event

  for (int i = 1; i <= 4; i++) {    //assing pinModes to buttons and their LEDs
    pinMode(button_Pins[i], INPUT_PULLUP);
    pinMode(LED_Pins[i], OUTPUT);
  }
}

void loop() {

  if (gamestatus > 0 && gamestatus < 5) {             //wait for game to be started by master controler
    pressedButton = checkButtons(); //check for pressed buttons
    BlinkLED(gamestatus);           //make the LED of the current stage blink

    if (pressedButton != lastPressedButton) { //exclude that button is being pressed and held
      lastPressedButton = pressedButton;

      if (pressedButton > 0 && pressedButton == answers[gamestatus]) { // check whether the right button was pressed
        progress();

        if (gamestatus == 5) {                                             // if last question was solved, send data to master
          win();
        }
      }
      else if (pressedButton > 0) {                                                               // if button was false
        fail();
      }
      updateProgressIndicator();                                           // uptate led indicator to current stage
    }
  }
  else runningLight(1);                                                    // play runlight in idle mode
  if (millis() > 3000 && gamestatus == 0) {
    gamestatus++;
  }
}
