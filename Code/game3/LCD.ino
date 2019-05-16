void printOnLCD(char line1[], char line2[]) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}

void print_serialnumber(){
  lcd.setCursor(0,2);
  for(int i = 0; i<8; i++){
    lcd.setCursor(i,2);
    lcd.print(input[i]);
  }
}

void addToLCD(int col, int row, char text[]) {
  lcd.setCursor(col, row);
  lcd.print(text);
}

void LCDpassword() {
  lcd.clear();

  for ( unsigned i = 0; i < pin_length; i++) {
    lcd.setCursor(i, 0);
    lcd.print(input[i]);
    Serial.print(input[i]);
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
