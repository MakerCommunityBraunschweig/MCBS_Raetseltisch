void gameReset(){
  timer=gametime;
  stage = 0;
  showTime();
  //send standby to stages
//  for(int i = 1 , i<=4, i++){
//    Wire.
//  }
  Serial.println("Game has been reset!");
}
