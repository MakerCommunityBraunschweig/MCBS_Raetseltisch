#include <Wire.h>

const int button_pin[5] = {0, 2, 3, 4, 5}; //makes use easier on other tabs
const int LED_Pins[5] = {0, 6, 7, 8, 9};  //makes use easier on other tabs

char output = 'o';
int gamestatus = 0;

bool LED_Status[5] = {false, false, false, false, false}; // Speicher für aktuellen Zustand der LED's
byte last_i = 0;

int pressedButton = 0;
int lastPressedButton = 0;
const int answers[] = {0, 3, 1, 2, 3};
unsigned int pressed_time[] = {0, 0, 0, 0, 0};
bool game_has_started = false;

void setup() {
  Serial.begin(9600);
  Wire.begin(2);                // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event

  for (int i = 1; i <= 4; i++) {    //assing pinModes to buttons and their LEDs
    pinMode(button_pin[i], INPUT_PULLUP);
    pinMode(LED_Pins[i], OUTPUT);
  }
}

void loop() {

  if (gamestatus > 0 && gamestatus < 5) {      //wait for game to be started by master controler
    pressedButton = checkButtons(); //check for pressed buttons
    BlinkLED(gamestatus);           //make the LED of the current stage blink
    if (game_has_started == false) {
      game_has_started = true;
      turnOffAllLEDs();
    }
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
  else if (gamestatus == 5) {
    runningLight(1, 10);
  }
  else blink_random();                                                   // play runlight in idle mode
}
