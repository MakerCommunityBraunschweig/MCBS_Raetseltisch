//Lässt die grünen Leds in der generierten Reinfolge leuchten
void blinkSequence() {
  Serial.println("Spiele Sequenz ab.");
  for (int i = 0; i < sizeof(sequence); i++) {
    digitalWrite(green_Led[sequence[i]], HIGH);
    delay(250);
    digitalWrite(green_Led[sequence[i]], LOW);
    delay(250);
  }
  Serial.println("Sequenz abgespielt. Erwarte Eingabe");
}

//Sucht nach gedrücktem Knopf und gibt dessen Wert zurück
int get_button() {
  if (digitalRead(button[1]) == LOW) {
    return 1;
    Serial.print("Knopf 1 gedrückt"); 
  }
  else if (digitalRead(button[2]) == LOW) {
    return 2;
    Serial.print("Knopf 2 gedrückt");
  }
  else if (digitalRead(button[3]) == LOW) {
    return 3;
    Serial.print("Knopf 3 gedrückt");
  }
  else if (digitalRead(button[4]) == LOW) {
    return 4;
    Serial.print("Knopf 4 gedrückt");
  }
  else return 0;
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
