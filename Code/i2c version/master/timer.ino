void updateTimer() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    switch (timer) {
      case 0:
        stage = 6;
        break;

      default:
        timer --;
    }
    showTime();
    buzzer.sound(NOTE_C6, 50);
  }
}

void showTimeSerial() {
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

void showTime() {
  int d = timer % 10;                 // Calculate 4 separate digits: [a b : c d]
  int b = timer / 60;
  int c = (timer - (b * 60) - d) / 10;

  showTimeSerial();              // Show time on serial monitor:  ab:cd
  tm1637.display(0, 0);                 // Show new time on display
  tm1637.display(1, b);
  tm1637.display(2, c);
  tm1637.display(3, d);
}
