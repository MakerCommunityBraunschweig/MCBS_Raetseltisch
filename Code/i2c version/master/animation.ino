void animationStartup(){
  Serial.println("initiating startup");
  //fancy LED - Animation
  //startup sound
  int notendauer = 300;
  buzzer.begin(5);
  buzzer.sound(NOTE_C6, 0.5*notendauer);
  buzzer.sound(NOTE_E6, 0.5*notendauer);
  buzzer.sound(NOTE_G6, notendauer);
  buzzer.sound(NOTE_E6, 0.5*notendauer);
  buzzer.sound(NOTE_G6, 4*notendauer);
  
  Serial.println("startup complete");
}

void animationGameOver(){
  int notendauer = 200;
  buzzer.begin(20);
  buzzer.sound(NOTE_DS5, 2*notendauer);
  buzzer.sound(NOTE_D5, 2*notendauer);
  buzzer.sound(NOTE_CS5, 2*notendauer);
  buzzer.sound(NOTE_C5, 4*notendauer);
}

void animationWin(){
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

void animationFC(){
  int n = 500;
  buzzer.begin(10);
  buzzer.sound(NOTE_FS5,  n);
  delay(150);
  buzzer.sound(NOTE_CS6,   0.25*n);
  buzzer.sound(NOTE_B5,  0.25*n);
  buzzer.sound(NOTE_CS6,   n);
  buzzer.sound(NOTE_FS5,  n);
    delay(150);
  buzzer.sound(NOTE_D6,   0.25*n);
  buzzer.sound(NOTE_CS6,  0.25*n);
  buzzer.sound(NOTE_D6,   0.5*n);
  buzzer.sound(NOTE_CS6,  0.5*n);
  buzzer.sound(NOTE_B5,   n);
      delay(150);
  buzzer.sound(NOTE_D6,   0.25*n);
  buzzer.sound(NOTE_CS6,  0.25*n);
  buzzer.sound(NOTE_D6,   0.5*n);
  buzzer.sound(NOTE_CS6,  0.5*n);
  buzzer.sound(NOTE_FS5,   n);
      delay(150);
  buzzer.sound(NOTE_B5,   0.25*n);
  buzzer.sound(NOTE_A5,  0.25*n);
  buzzer.sound(NOTE_B5,   0.5*n);
  buzzer.sound(NOTE_A5,  0.5*n);
  buzzer.sound(NOTE_B5,   n);
}
