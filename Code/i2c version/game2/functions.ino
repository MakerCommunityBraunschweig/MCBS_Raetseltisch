
/*return the number of the pressed button */
int checkButtons() {        
  if (digitalRead(button1) == LOW) {
    return 1;
  }
  else if (digitalRead(button2) == LOW) {
    return 2;
  }
  else if (digitalRead(button3) == LOW) {
    return 3;
  }
  else if (digitalRead(button4) == LOW) {
    return 4;
  }
  else return 0;
}


// ------ Methods used for control of the four button LEDs --------

/* turn on the leds according to the gamestatus*/
void updateProgressIndicator() {
  for (int i = 1; i < gamestatus ; i++) {   //eg gamestatus ==1 -> no questions solved -> no led on
    turnOnLED(i);
  }
  for (int i = gamestatus; i < 5; i++) {    //eg gamestatus ==5 -> all questions solved -> all leds on
    if (i > 0) {
      turnOffLED(i);
    }
  }
}

/* Turn on the selected LED */
void turnOnLED(int LEDnum) {
  LED_Status[LEDnum] = 1;
  digitalWrite(LED_Pins[LEDnum], HIGH);
}

void turnOnAllLEDs() {
  for (int i = 1; i <= 4; i++) {
    LED_Status[i] = 1;
    digitalWrite(LED_Pins[i], HIGH);
  }
}

/* Turn off the selected LED */
void turnOffLED(int LEDnum) {
  LED_Status[LEDnum] = 0;
  digitalWrite(LED_Pins[LEDnum], LOW);
}

void turnOffAllLEDs() {
  for (int i = 1; i <= 4; i++) {
    LED_Status[i] = 0;
    digitalWrite(LED_Pins[i], LOW);
  }
}


void runningLight(int iter) {
  for (int j = 1; j <= iter; j++) {
    for (int i = 1; i <= 4; i++) {
      turnOnLED(i);
      delay(100);
    }
    for (int i = 1; i <= 4; i++) {
      turnOffLED(i);
      delay(100);
    }
  }
}

void BlinkLED(int LEDnum) {                       //lasse LED im interval von 1 sek blinken, falls dauerhaft aufgerufen
  if (LEDnum < 5 && (millis() / 1000) % 2 == 0) {
    turnOnLED(LEDnum);
  }
  else turnOffLED(LEDnum);
}

void BlinkAllLEDs() {
  for (int i = 1; i <= 3; i++) {
    turnOnAllLEDs();
    delay(200);
    turnOffAllLEDs();
    delay(200);
  }
}
