boolean array_cmp(byte *a, byte *b) {
  // test each element to be the same. if not, return false
  for (int i = 0; i < 4; i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  //ok, if we have not returned yet, they are equal :)
  return true;
}

int getCardnumber() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial() ) {
    Serial.print("Gelesene UID:");
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i]);
      Serial.print(" ");
    }
    Serial.println();
    if (array_cmp(rfid.uid.uidByte, UID1) == true) {
      Serial.println("Karte 1 erkannt.");
      delay(500);
      rfid.PICC_HaltA();
      return 1;
    }
    else if (array_cmp(rfid.uid.uidByte, UID2) == true) {
      Serial.println("Karte 2 erkannt.");
      delay(500);
      rfid.PICC_HaltA();
      return 2;
    }
    else if (array_cmp(rfid.uid.uidByte, UID3) == true) {
      Serial.println("Karte 3 erkannt.\n");
      delay(500);
      rfid.PICC_HaltA();
      return 3;
    }
    else {
      Serial.println("Unbekannte Karte erkannt.");
      delay(500);
      rfid.PICC_HaltA();
      return 0;
    }
  }
  else {
    rfid.PICC_HaltA();
    return 0;
  }
}

void updateProgressLed() {
  switch (gamestatus) {
    case 0:
    case 1:
      digitalWrite(progressLED1, LOW);
      digitalWrite(progressLED2, LOW);
      digitalWrite(progressLED3, LOW);
      break;
    case 2:
      digitalWrite(progressLED1, HIGH);
      break;
    case 3:
      digitalWrite(progressLED2, HIGH);
      break;
    case 4:
      digitalWrite(progressLED3, HIGH);
      break;
  }
}

//Auszuführen, falls eine richtige Karte eingesteckt wurde
void progress() {
  gamestatus++;
  Serial.println("Richtig! Nächste Karte\n");
  digitalWrite(gLED, HIGH);
  delay (1000);
  digitalWrite(gLED, LOW);
}

//Setzt das Spiel in den Ausgangszustand zurück
void reset() {
  gamestatus = 0;
  Serial.println("Das Spiel wurde zurückgesetzt");
}

//Auszuführen, falls Spiel gelöst wurde
void win() {
  output = 's';
  Serial.println("Bravo! Station gelöst!\n");
  gamestatus++;
}

//Auszuführen, falls ein Fehler gemacht wurde
void fail() {
  output = 'f';
  gamestatus = 1;
  Serial.println("Falsch! Nochmal von vorne!\n");
  for ( int i = 0, i < 3, i++) {
    digitalWrite(rLED, HIGH);
    delay (250);
    digitalWrite(rLED, LOW);
    delay(250);
  }
}
