void checkPin() {
  // Eingabe mit festgelegtem Pincode vergleichen
  if (strcmp(keyBuffer, pinCode) == 0) {
    Serial.println("Richtige Seriennummer eingegeben.");
    // Aktion für richtigen Pin ausführen
    pinCorrect();
  }
  else if (inputLength != pinLength) {
    pinShort();
  }
  else {
    Serial.println("Falsche Seriennummer eingegeben.");
    // Aktion für falschen Pin ausführen
    pinWrong();
  }

  // Nach Überprüfung Eingabe leeren
  for (int i = 0; i < PINLENGTH; i++) {
    keyBuffer[i] = '-';
  }
}

// Aktion für korrekten Pincode
void pinCorrect() {
  output = 's';
  gamestatus= 2;
  printOnLCD("Eingabe         ";"korrekt         ");
}

// Aktion für falschen Pincode
void pinWrong() {
  for ( int i = 0; i < pinLength; i++) {
    keyBuffer[i] = '-';
  }
  output = 'f';
  printOnLCD("Eingabe         ","ungueltig       ");
  delay(1000);
  printOnLCD("Seriennummer:   ", "                ");
}

void pinShort() {
  printOnLCD("Eingabe           ", "unvollstaendig  ");
}
