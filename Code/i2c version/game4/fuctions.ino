//Lässt die grünen Leds in der generierten Reinfolge leuchten
void blinkSequence() {
  Serial.println("Spiele Sequenz ab.");
  for (int i = 0; i < sizeof(sequence); i++) {
    digitalWrite(green_Led[sequence[i]], HIGH);
    delay(150);
    digitalWrite(green_Led[sequence[i]], LOW);
    delay(150);
  }
  Serial.println("Sequenz abgespielt. Erwarte Eingabe");
}

//Sucht nach gedrücktem Knopf und gibt dessen Wert zurück
int get_button() {
  for (int i = 1; i <= 4; i++) {
    if (digitalRead(button[i]) == LOW) {
      Serial.print("Knopf ");
      Serial.print(i);
      Serial.println(" gedrückt.");
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
