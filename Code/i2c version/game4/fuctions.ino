//Lässt die grünen Leds in der generierten Reinfolge leuchten
void blinkSequence() {
  for (int i = 0; i < sizeof(sequence); i++) {
    digitalWrite(green_Led[sequence[i]], HIGH);
    delay(375);
    digitalWrite(green_Led[sequence[i]], LOW);
  }
  delay(1000);
}

//Sucht nach gedrücktem Knopf und gibt dessen Wert zurück
int get_button() {
  for (int i = 1; i <= 4; i++) {
    if (digitalRead(button[i]) == LOW) {
      return (i);
    }
    else return 0;
  }
}

//Vergleicht die Einträge zweier Arrays und gibt bei gleichheit 'true' zurück
bool array_comp(byte* a, byte* b) {
  for (int i = 0; i < sizeof(a); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

//Setzt das Spiel in den Ausgangsmodus zurück
void reset() {
  Serial.println("Setze Spiel zurück:");
  gamestatus = 0;
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
  Serial.println("\n");
  Serial.println("Das Spiel wurde zurückgesetzt.");
}

//Auszuführende Befehle, falls falsche Sequenz eingegeben
void fail() {
  output = 'f';
  gamestatus = 1;
  input_length = 0;
}

//Auszuführende Befehlen, falls richtige Sequenz eingegeben
void win() {
  output = 's';
  gamestatus = 3;
}
