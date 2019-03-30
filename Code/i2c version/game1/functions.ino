int cardcolour() {
  if (colourCardIn() == false) {
    return 0;
  }
  else if ((red < green) && (green > blue)) {
    Serial.println("Red!");
    return 1;
  }
  else if ((red > green) && (green < blue)) {
    Serial.println("Yellow!");
    return 2;
  }
  else if ((red > green) && (green > blue)) {
    Serial.println("Blue!");
    return 3;
  }
}

void colourSense() {
  // Setting RED photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading and saving
  red = pulseIn(sensorOut, LOW);
  Serial.print("R = ");
  Serial.print(red);
  Serial.print("  ");
  delay(10);

  // Setting GREEN photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading and saving
  green = pulseIn(sensorOut, LOW);
  Serial.print("G = ");
  Serial.print(green);
  Serial.print("  ");
  delay(10);

  // Setting BLUE photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading and saving
  blue = pulseIn(sensorOut, LOW);
  Serial.print("B = ");
  Serial.print(blue);
  Serial.println("  ");
  delay(10);
}

void waitForRemove() {
  while (colourCardIn() == true) {
    delay(100);
  }
}

bool colourCardIn() { // testing to see if card is in the slot with green triggerLED
  int r = 63;
  int g = 50;
  int b = 50;
  int tol = 50;
  if ((red >= (r - tol)) && (red <= (r + tol)) && (green >= (g - tol))
      && (green <= (g + tol)) && (blue >= (b - tol)) && (blue <= (b + tol))) {
    digitalWrite(rLED, HIGH);
    digitalWrite(gLED, LOW);
    Serial.println("Card slot empty!");
    return false;
  }
  else {
    return true;
  }
}

void updateProgressLed() {
  switch (gamestatus) {
    case 0:
      digitalWrite(progressLED1, LOW);
      digitalWrite(progressLED2, LOW);
      digitalWrite(progressLED3, LOW);
      break;
    case 1:
      digitalWrite(progressLED1, HIGH);
      break;
    case 2:
      digitalWrite(progressLED2, HIGH);
      break;
    case 3:
      digitalWrite(progressLED3, HIGH);
      break;
  }
}
