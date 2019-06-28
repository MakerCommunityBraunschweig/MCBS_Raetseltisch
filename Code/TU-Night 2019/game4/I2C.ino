void requestEvent() {
  Wire.write(output); // respond with message of 1 bytes
  output = 'o';       // overwrite sent data with something else to avoid sending the same data twice
}

void receiveEvent(int howMany) {
  while (1 <= Wire.available()) {// loop through all but the last
    char input = Wire.read();   // receive byte as a character
    Serial.print("Empfange Daten: ");
    Serial.println(input);        // print the character
    switch  (input) {
      case 'a':
        output = 'a';
        gamestatus = 1;         //start the game
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
