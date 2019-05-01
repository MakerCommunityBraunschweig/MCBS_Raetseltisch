void win() {
  animationWin();
  Serial.println("Gewonnen!");
  Serial.print("Spielzeit: ");
  Serial.println((300000 - previousMillis) / 1000);
}

void fail() {
  animationGameOver();
  Serial.println("Game over!");
}

void progress() {

}

void wait_for_reset(){
  if(digitalRead(reset_button)==HIGH){
    reset();
  }
}

void reset() {
  timer = gametime;
  stage = 0;
  showTime();
  for (int i = 1 ; i <= 4; i++) {
    Wire.beginTransmission(i);  // transmit to device
    Wire.write('r');                // reset game
    Wire.endTransmission();
  }
  Serial.println("Spiel wurde zurückgesetzt");
}
