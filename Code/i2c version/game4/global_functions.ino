
//Setzt das Spiel in den Ausgangsmodus zurück und generiert eine neue Sequenz
void reset() {
  gamestatus = 0;
  Serial.print("Gamestatus: ");
  Serial.println(gamestatus);
  Serial.print("Neue Sequenz: ");
  for (int i = 0; i < sizeof(sequence); i++) {
    randomSeed(analogRead(A7)*analogRead(A2));
    sequence[i] = random(1, 5);
    if (i > 0) {
      while (sequence[i] == sequence[i - 1]) {
        sequence[i] = random(1, 5);
      }
    }
    input[i] = 0;
    Serial.print(sequence[i]);
    Serial.print(" ");
  }
  input_length = 0;
  Serial.println();
  Serial.println("Das Spiel wurde zurückgesetzt.");
}

void progress() {
  gamestatus++;
}

//Auszuführende Befehlen, falls richtige Sequenz eingegeben
void win() {
  Serial.print("Eingegebene Sequenz ' ");
  for (int i = 0; i < sizeof(sequence); i++) {
    Serial.print(input[i]);
    Serial.print(" ");
  }
  Serial.println("' ist richtig.\n");
  output = 's';
  for (int j = 0; j < 5; j++) {
    for ( int i = 1; i < 5; i++) {
      digitalWrite(red_Led[i], HIGH);
      digitalWrite(green_Led[i], HIGH);
    }
    delay(250);
    for ( int i = 1; i < 5; i++) {
      digitalWrite(red_Led[i], LOW);
      digitalWrite(green_Led[i], LOW);
    }
    delay(250);
  }
  reset();
}

//Auszuführende Befehle, falls falsche Sequenz eingegeben
void fail() {
  Serial.print("Eingegebene Sequenz ' ");
  for (int i = 0; i < sizeof(sequence); i++) {
    Serial.print(input[i]);
    Serial.print(" ");
  }
  Serial.println("' ist falsch.\n");
  //Lasse rote LEDS blinken
  output = 'f';
  gamestatus = 1;
  input_length = 0;
}
