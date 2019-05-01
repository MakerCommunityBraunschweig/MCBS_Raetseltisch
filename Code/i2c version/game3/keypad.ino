void checkPin() {
  // Eingabe mit festgelegtem Pincode vergleichen
  if (strcmp(input, pin_code) == 0) {
    Serial.println("Richtige Seriennummer eingegeben.");
    // Aktion für richtigen Pin ausführen
    win();
  }
  else if (input_length != pin_length) {
    pinShort();
  }
  else {
    Serial.println("Falsche Seriennummer eingegeben.");
    // Aktion für falschen Pin ausführen
    fail();
  }

  // Nach Überprüfung Eingabe leeren
  for (int i = 0; i < pin_length; i++) {
    input[i] = '-';
  }
}

void pinShort() {
  printOnLCD("Eingabe           ", "unvollstaendig  ");
}
