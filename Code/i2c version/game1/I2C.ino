void requestEvent() {
  Wire.write(output); // respond with message of 1 bytes
  output = 'o';
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char input = Wire.read(); // receive byte as a character
    Serial.print(input);         // print the character
    if (input == 'a') {
      gamestatus++;
    }
  }
}
