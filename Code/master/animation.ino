void animation_startup() {
  int n = 300;
  buzzer.begin(5);
  buzzer.sound(NOTE_C6, 0.5 * n);
  buzzer.sound(NOTE_E6, 0.5 * n);
  buzzer.sound(NOTE_G6, n);
  buzzer.sound(NOTE_E6, 0.5 * n);
  buzzer.sound(NOTE_G6, 4 * n);
}

void animationGameOver() {
  int n = 2000;
  buzzer.begin(20);
  buzzer.sound(piepton, n);
}

void animationWin() {
  buzzer.begin(100);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_G7, 80);
  buzzer.sound(0, 240);
  buzzer.sound(NOTE_G6, 80);
  buzzer.sound(0, 240);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_G6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_E6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_AS6, 80);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_G6, 100);
  buzzer.sound(NOTE_E7, 100);
  buzzer.sound(NOTE_G7, 100);
  buzzer.sound(NOTE_A7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_F7, 80);
  buzzer.sound(NOTE_G7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(NOTE_D7, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_G6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_E6, 80);
  buzzer.sound(0, 160);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_AS6, 80);
  buzzer.sound(NOTE_A6, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_G6, 100);
  buzzer.sound(NOTE_E7, 100);
  buzzer.sound(NOTE_G7, 100);
  buzzer.sound(NOTE_A7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_F7, 80);
  buzzer.sound(NOTE_G7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_E7, 80);
  buzzer.sound(0, 80);
  buzzer.sound(NOTE_C7, 80);
  buzzer.sound(NOTE_D7, 80);
  buzzer.sound(NOTE_B6, 80);
  buzzer.sound(0, 160);

  buzzer.end(2000);
}

void animationFC() {
  int n = 500;
  buzzer.begin(10);
  buzzer.sound(NOTE_FS5,  n);
  delay(150);
  buzzer.sound(NOTE_CS6,   0.25 * n);
  buzzer.sound(NOTE_B5,  0.25 * n);
  buzzer.sound(NOTE_CS6,   n);
  buzzer.sound(NOTE_FS5,  n);
  delay(150);
  buzzer.sound(NOTE_D6,   0.25 * n);
  buzzer.sound(NOTE_CS6,  0.25 * n);
  buzzer.sound(NOTE_D6,   0.5 * n);
  buzzer.sound(NOTE_CS6,  0.5 * n);
  buzzer.sound(NOTE_B5,   n);
  delay(150);
  buzzer.sound(NOTE_D6,   0.25 * n);
  buzzer.sound(NOTE_CS6,  0.25 * n);
  buzzer.sound(NOTE_D6,   0.5 * n);
  buzzer.sound(NOTE_CS6,  0.5 * n);
  buzzer.sound(NOTE_FS5,   n);
  delay(150);
  buzzer.sound(NOTE_B5,   0.25 * n);
  buzzer.sound(NOTE_A5,  0.25 * n);
  buzzer.sound(NOTE_B5,   0.5 * n);
  buzzer.sound(NOTE_A5,  0.5 * n);
  buzzer.sound(NOTE_B5,   n);
}

void ente() {
  int n = 500;
  buzzer.begin(10);
  buzzer.sound(NOTE_C5, 0.5 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_E5, 0.5 * n);
  buzzer.sound(NOTE_F5, 0.5 * n);
  buzzer.sound(NOTE_G5, n);
  buzzer.sound(NOTE_G5, n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_G5, 2 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_A5, 0.5 * n);
  buzzer.sound(NOTE_G5, 2 * n);
  buzzer.sound(NOTE_F5, 0.5 * n);
  buzzer.sound(NOTE_F5, 0.5 * n);
  buzzer.sound(NOTE_F5, 0.5 * n);
  buzzer.sound(NOTE_F5, 0.5 * n);
  buzzer.sound(NOTE_E5, n);
  buzzer.sound(NOTE_E5, n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_C5, 2 * n);
}

void starwars() {
  buzzer.begin(10);

  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);

  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_A3, 1000);

  buzzer.sound(NOTE_E4, 500);
  buzzer.sound(NOTE_E4, 500);
  buzzer.sound(NOTE_E4, 500);
  buzzer.sound(NOTE_F4, 375);
  buzzer.sound(NOTE_C4, 125);

  buzzer.sound(NOTE_GS3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_A3, 1000);

  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_A3, 375);
  buzzer.sound(NOTE_A3, 125);
  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_GS4, 375);
  buzzer.sound(NOTE_G4, 125);

  buzzer.sound(NOTE_FS4, 125);
  buzzer.sound(NOTE_E4, 125);
  buzzer.sound(NOTE_F4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_AS3, 250);
  buzzer.sound(NOTE_DS4, 500);
  buzzer.sound(NOTE_D4, 375);
  buzzer.sound(NOTE_CS4, 125);

  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_B3, 125);
  buzzer.sound(NOTE_C4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_F3, 250);
  buzzer.sound(NOTE_GS3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_A3, 125);

  buzzer.sound(NOTE_C4, 500);
  buzzer.sound(NOTE_A3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_E4, 1000);

  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_A3, 375);
  buzzer.sound(NOTE_A3, 125);
  buzzer.sound(NOTE_A4, 500);
  buzzer.sound(NOTE_GS4, 375);
  buzzer.sound(NOTE_G4, 125);

  buzzer.sound(NOTE_FS4, 125);
  buzzer.sound(NOTE_E4, 125);
  buzzer.sound(NOTE_F4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_AS3, 250);
  buzzer.sound(NOTE_DS4, 500);
  buzzer.sound(NOTE_D4, 375);
  buzzer.sound(NOTE_CS4, 125);

  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_B3, 125);
  buzzer.sound(NOTE_C4, 250);
  buzzer.sound(0, 250);
  buzzer.sound(NOTE_F3, 250);
  buzzer.sound(NOTE_GS3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);

  buzzer.sound(NOTE_A3, 500);
  buzzer.sound(NOTE_F3, 375);
  buzzer.sound(NOTE_C4, 125);
  buzzer.sound(NOTE_A3, 1000);

  buzzer.end(2000);
}

void vogel() {
  int n = 2000;
  buzzer.begin(10);
  buzzer.sound(NOTE_C5, (0.25 + 0.125) * n);
  buzzer.sound(NOTE_E5, 0.125 * n);
  buzzer.sound(NOTE_G5, 0.25 * n);
  buzzer.sound(NOTE_C6, 0.25 * n);
  buzzer.sound(NOTE_A5, 0.25 * n);
  buzzer.sound(NOTE_C6, 0.125 * n);
  buzzer.sound(NOTE_A5, 0.125 * n);
  buzzer.sound(NOTE_G5, 0.5 * n);
  buzzer.sound(NOTE_F5, 0.375 * n);
  buzzer.sound(NOTE_G5, 0.125 * n);
  buzzer.sound(NOTE_E5, 0.25 * n);
  buzzer.sound(NOTE_C5, 0.25 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_C5, 0.25 * n);
  delay(0.25 * n);

  buzzer.sound(NOTE_G5, 0.25 * n);
  buzzer.sound(NOTE_G5, 0.25 * n);
  buzzer.sound(NOTE_F5, 0.25 * n);
  buzzer.sound(NOTE_F5, 0.25 * n);
  buzzer.sound(NOTE_E5, 0.25 * n);
  buzzer.sound(NOTE_G5, 0.125 * n);
  buzzer.sound(NOTE_E5, 0.125 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_G5, 0.25 * n);
  buzzer.sound(NOTE_G5, 0.25 * n);
  buzzer.sound(NOTE_F5, 0.25 * n);
  buzzer.sound(NOTE_F5, 0.25 * n);
  buzzer.sound(NOTE_E5, 0.25 * n);
  buzzer.sound(NOTE_G5, 0.125 * n);
  buzzer.sound(NOTE_E5, 0.125 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);

  buzzer.sound(NOTE_C5, 0.375 * n);
  buzzer.sound(NOTE_E5, 0.125 * n);
  buzzer.sound(NOTE_G5, 0.25 * n);
  buzzer.sound(NOTE_C6, 0.25 * n);
  buzzer.sound(NOTE_A5, 0.25 * n);
  buzzer.sound(NOTE_C6, 0.125 * n);
  buzzer.sound(NOTE_A5, 0.125 * n);
  buzzer.sound(NOTE_G5, 0.5 * n);
  buzzer.sound(NOTE_F5, 0.375 * n);
  buzzer.sound(NOTE_G5, 0.125 * n);
  buzzer.sound(NOTE_E5, 0.25 * n);
  buzzer.sound(NOTE_C5, 0.25 * n);
  buzzer.sound(NOTE_D5, 0.5 * n);
  buzzer.sound(NOTE_C5, 0.5 * n);
}

void knack() {
  buzzer.begin(10);
  for (int i = 0; i < 20; i++) {
    buzzer.sound(NOTE_C1, 10);
    delay(100);
  }
  buzzer.end(2000);
}
