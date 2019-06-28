void win() {
  Serial.println("Gewonnen!");
  Serial.print("Spielzeit: ");
  int spielzeit = previousMillis / 1000;
  int d = spielzeit % 10;                 // Calculate 4 separate digits: [a b : c d]
  int b = spielzeit / 60;
  int c = (spielzeit - (b * 60) - d) / 10;

  Serial.print(0);
  Serial.print(b);
  Serial.print(':');
  Serial.print(c);
  Serial.print(d);
  Serial.print('\n');
  animationWin();
}

void game_over() {
  animationGameOver();
  Serial.println("Game over!");
}

void wait_for_reset() {
  if (digitalRead(startbutton) == LOW) {
    Serial.print("RESET!");
    reset();
    delay(1000);
  }
}

void reset() {
  timer = gametime;
  stage = 0;
  interval = 1000;
  update_display();
  for (int i = 1 ; i <= 4; i++) {
    Wire.beginTransmission(i);  // transmit to device
    Wire.write('r');            // reset game
    Wire.endTransmission();
  }
  Serial.println("Spiel wurde zurückgesetzt");
}
