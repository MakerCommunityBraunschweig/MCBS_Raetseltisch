bool update_timer() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis;
    if (timer <= 0) {
      stage = 6;
      timer = 0;
    }
    else timer--;
    return true;
  }
  else return false;
}

void beep() {
  unsigned long currentMillis = millis();
  if (timer < 60) interval = 500;
  if (timer < 30) interval = 250;
  if (timer < 30) interval = 125;

  if (currentMillis - previousMillis2 > interval) {
    previousMillis2 = currentMillis;
    Serial.println("Beep");
    buzzer.sound(piepton, 40);
  }
}

void update_display() {
  int d = timer % 10;                 // Calculate 4 separate digits: [a b : c d]
  int b = timer / 60;
  int c = (timer - (b * 60) - d) / 10;

  tm1637.display(0, 0);                 // Show new time on display
  tm1637.display(1, b);
  tm1637.display(2, c);
  tm1637.display(3, d);
}

void serial_print_time() {
  int d = timer % 10;                 // Calculate 4 separate digits: [a b : c d]
  int b = timer / 60;
  int c = (timer - (b * 60) - d) / 10;

  Serial.print(0);
  Serial.print(b);
  Serial.print(':');
  Serial.print(c);
  Serial.print(d);
  Serial.print('\n');
}
