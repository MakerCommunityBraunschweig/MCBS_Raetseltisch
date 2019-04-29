void printOnLCD(char line1[], char line2[]) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void addToLCD(int col, int row, char text[]) {
  lcd.setCursor(col, row);
  lcd.print(text);
}

void LCDwelcomeScreen() {
  printOnLCD("Enter Serial Nr:", "   ===MCBS===");
}

void resetKeypad() {
  char keyword_in[_dimSerialNr] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  counter = 0;
  Serial.println(keyword_in);
}

void LCDmoreNumbers() {
  printOnLCD("    Requires", "  more digits!");
  delay(2000);
}

void LCDpassword() {
  lcd.clear();

  for ( unsigned i = 0; i < _dimSerialNr; i++) {
    lcd.setCursor(i, 0);
    lcd.print(keyword_in[i]);
    Serial.print(keyword_in[i]);
  }
  Serial.print('\n');
  addToLCD(0, 1, "#Delete *Confirm");
}

void LCDdotting(int pos, int row) {
  for (int i = pos; i <= 16 - pos; i++) {
    addToLCD(i, row, ".");
    delay(100);
  }
}

/* Appears when Keypad Game has been finished */
void LCDcorrect() {
  printOnLCD("Processing..", "");
  for (int i = 3; i >= 1; i--) {
    lcd.setCursor(0, 1);
    lcd.print(i);
    LCDdotting(1, 1);
  }
  delay(1500);
  printOnLCD("  Next Station", "   Unlocked!");
  delay(3000);
  lcd.clear();
}
