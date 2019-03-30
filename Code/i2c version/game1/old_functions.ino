/* Main Method of Colour Cards Game

*/
//void colourCards() {
//  switch (colourCardCounter) {
//    case 0:
//      digitalWrite(progressLED1, LOW);
//      digitalWrite(progressLED2, LOW);
//      digitalWrite(progressLED3, LOW);
//      break;
//    case 1:
//      digitalWrite(progressLED1, HIGH);
//      break;
//    case 2:
//      digitalWrite(progressLED2, HIGH);
//      break;
//    case 3:
//      digitalWrite(progressLED3, HIGH);
//      break;
//  }
//
//
//  colourSense();
//  detectedColor = _nothing;
//
//  // Reading cards, comparing rgb values
//  if (colourCardIn()) {
//
//    for (int n = 1; n <= 10; n++) {
//      colourSense();
//      if (colourCardRed()) {
//        detectedColor = _red;
//      }
//      if (colourCardYellow()) {
//        detectedColor = _yellow;
//      }
//      if (colourCardBlue()) {
//        detectedColor = _blue;
//      }
//    }
//
//
//  }
//
//
//  if (colourCardIn() && colourCardRemoved) {
//    for (int i = 0; i < 3; i++) { // takes the third value
//      colourSense();
//    }
//    if (colourCardCounter == 0 && detectedColor == _red) {
//      colourCardCounter = 1;
//      digitalWrite(rLED, LOW);
//      digitalWrite(gLED, HIGH);
//      colourCardRemoved = false; // this prevents the loop from comparing the
//      //current red card in the slot with colourCardCounter = 1;
//      // = true will trigger when card is removed in colourCardIn();
//      Serial.println("Card is Red!");
//    }
//    else if (colourCardCounter == 1 && detectedColor == _yellow) {
//      colourCardCounter = 2;
//      digitalWrite(rLED, LOW);
//      digitalWrite(gLED, HIGH);
//      colourCardRemoved = false;
//      Serial.println("Card is Yellow!");
//    }
//    else if (colourCardCounter == 2 && detectedColor == _blue) {
//      // COLOURUNLOCKED!
//      colourCardCounter = 3;
//      digitalWrite(rLED, LOW);
//      digitalWrite(gLED, HIGH);
//      colourCardRemoved = false;
//      Serial.println("Card is Blue!");
//      // Shut down colour sensor
//      digitalWrite(S0, LOW);
//      digitalWrite(S1, LOW);
//
//      ColourCardsFinished = 1;
//      digitalWrite(progressLED3, HIGH);
//      // visual and/or audio cue
//
//      // lock this station and unlock next station/prize
//
//    }
//    else { // What happens when the card is inserted in the wrong sequence
//      colourCardCounter = 0; // here we start over
//      // visual and/or audio cue
//      for (int i = 0; i < 3; i++) { // blinks five times
//        digitalWrite(rLED, LOW);
//        digitalWrite(gLED, LOW);
//        delay(300);
//        digitalWrite(rLED, HIGH);
//        delay(300);
//      }
//      colourCardRemoved = false;
//      digitalWrite(rLED, HIGH);
//      digitalWrite(gLED, LOW);
//    }
//  }
//}
