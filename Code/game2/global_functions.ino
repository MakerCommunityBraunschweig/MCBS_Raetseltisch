void progress() {
  gamestatus ++;
  Serial.print("Gamestatus");
  Serial.println(gamestatus);
}

void win() {
  output = 's';
  Serial.println("Spielende");
}

void fail() {
  Serial.println("WRONG!");
  output = 'f';        // send according data to master
  BlinkAllLEDs(3);      // play an animation
  gamestatus = 1;      // return to first question
}
