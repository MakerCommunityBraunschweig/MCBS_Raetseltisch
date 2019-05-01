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
