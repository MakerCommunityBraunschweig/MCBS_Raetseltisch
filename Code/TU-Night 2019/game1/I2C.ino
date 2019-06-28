void requestEvent() {
  Wire.write(output); // sende, was aktuell in output gespeichert ist
  output = 'o';       // überschreibe den output nun mit einem irrelevanten wert,um ein doppeltes senden der Daten zu vermeiden
}

void receiveEvent(int howMany) { // wenn daten empfangen werden
  while (1 <= Wire.available()) {// loop through all but the last
    char input = Wire.read();   // receive byte as a character
    Serial.print("Empfangende Daten: ");
    Serial.println(input);        // print the character
    switch  (input) {   // führe je nach Input verschiedene aktionen aus
      case 'a':
        gamestatus = 1;         //start the game
        output= 'a';
        Serial.println("Das Spiel wurde aktiviert");
        break;

      case 'r':                 //reset the game
        reset();
        break;

      default:
        Serial.print("Ungültiger Input: ");
        Serial.println(input);
    }
  }
}
