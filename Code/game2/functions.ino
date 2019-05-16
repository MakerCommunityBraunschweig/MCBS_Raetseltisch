
/*return the number of the pressed button */
int checkButtons() {
  if (digitalRead(button_pin[1]) == LOW && millis() - pressed_time[1] > 1000) {
    Serial.println("Knopf 1");
    pressed_time[1] = millis();
    return 1;
  }
  else if (digitalRead(button_pin[2]) == LOW && millis() - pressed_time[2] > 1000) {
    Serial.println("Knopf 2");
    pressed_time[2] = millis();
    return 2;
  }
  else if (digitalRead(button_pin[3]) == LOW && millis() - pressed_time[3] > 1000) {
    Serial.println("Knopf 3");
    pressed_time[3] = millis();
    return 3;
  }
  else if (digitalRead(button_pin[4]) == LOW && millis() - pressed_time[4] > 1000) {
    Serial.println("Knopf 4");
    pressed_time[4] = millis();
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
  digitalWrite(LED_Pins[LEDnum], HIGH);
}

void turnOnAllLEDs() {
  for (int i = 1; i <= 4; i++) {
    digitalWrite(LED_Pins[i], HIGH);
  }
}

/* Turn off the selected LED */
void turnOffLED(int LEDnum) {
  digitalWrite(LED_Pins[LEDnum], LOW);
}

void turnOffAllLEDs() {
  for (int i = 1; i <= 4; i++) {
    digitalWrite(LED_Pins[i], LOW);
  }
}

void runningLight(int iter, int speed) {
  for (int j = 1; j <= iter; j++) {
    for (int i = 1; i <= 4; i++) {
      turnOnLED(i);
      delay(1000 / speed);
    }
    for (int i = 1; i <= 4; i++) {
      turnOffLED(i);
      delay(1000 / speed);
    }
  }
}

void BlinkLED(int LEDnum) {                       //lasse LED im interval von 1 sek blinken, falls dauerhaft aufgerufen
  if (LEDnum < 5 && (millis() / 750) % 2 == 0) {
    turnOnLED(LEDnum);
  }
  else turnOffLED(LEDnum);
}

void BlinkAllLEDs(int j) {
  for (int i = 1; i <= j; i++) {
    turnOnAllLEDs();
    delay(200);
    turnOffAllLEDs();
    delay(200);
  }
}
void blink_random() {
  if (millis() % 1250 == 0) {
    randomSeed (analogRead(A2));
    byte i = random(1, 5);
    while (i == last_i) {
      i = random(1, 5);
    }
    last_i = i;
    LED_Status[i] = !LED_Status[i];
    digitalWrite(LED_Pins[i], LED_Status[i]);
    delay(25);
  }
}
