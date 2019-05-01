
//Setzt das Spiel in den Ausgangsmodus zurück und generiert eine neue Sequenz
void reset() {
  gamestatus = 1;
  Serial.print("Gamestatus: ");
  Serial.println(gamestatus);
  Serial.print("Neue Sequenz: ");
  for (int i = 0; i < sizeof(sequence); i++) {
    sequence[i] = random(1, 4);
    input[i] = 0;
    Serial.print(sequence[i]);
    Serial.print(" ");
  }
  byte input_length = 0;
  Serial.println();
  Serial.println("Das Spiel wurde zurückgesetzt.");
}

void progress() {
  gamestatus++;
}

//Auszuführende Befehlen, falls richtige Sequenz eingegeben
void win() {
  output = 's';
  gamestatus = 0;
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
