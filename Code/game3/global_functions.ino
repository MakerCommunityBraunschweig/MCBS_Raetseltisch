
//Setzt das Spiel in den Ausgangsmodus zurück und generiert eine neue Sequenz
void reset() {
  Serial.println("Setze Spiel zurück:");
  gamestatus = 0;
  Serial.print("Gamestatus: ");
  Serial.println(gamestatus);
  for ( int i = 0; i < pin_length; i++) {
    input[i] = '-';
  }
  input_length = 0;
  Serial.println("\n");
  Serial.println("Das Spiel wurde zurückgesetzt.");
  lcd.clear();
  printOnLCD("Standby- Modus", "");
  screen1 = false;
}

void progress() {
  gamestatus++;
}

//Auszuführende Befehlen, falls richtige Sequenz eingegeben
void win() {
  output = 's';
  gamestatus = 0;
  printOnLCD("Eingabe         ", "korrekt         ");
  delay(1000);
  printOnLCD("Naechstes Modul", "freigeschaltet");
  screen1 = false;
}

//Auszuführende Befehle, falls falsche Sequenz eingegeben
void fail() {
  output = 'f';
  for ( int i = 0; i < pin_length; i++) {
    input[i] = '-';
  }
  input_length = 0;
  printOnLCD("Eingabe         ", "ungueltig       ");
  delay(1000);
  screen1 = false;
}
