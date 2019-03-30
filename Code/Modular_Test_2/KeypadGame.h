
// ------------ Definition of Keypad -------------- //
const byte ROWS = 4;          //four rows
const byte COLS = 3;          //three columns

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the kg_inputpad
byte colPins[COLS] = {4, 3, 2};    //connect to the column pinouts of the kg_inputpad

Keypad keypad1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int KeypadFinished = 0;       // Variable to indicate that game has finished


// ------------ Definition of LCD Display -------------- //
LiquidCrystal lcd(14, 13, 12, 11, 10, 9);

//---------------- How to solve the Keypad Game ------------//
#define _dimSerialNr 8 // Size of Keypad Array

char keyword_in[_dimSerialNr] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char keyword_set[_dimSerialNr] = {'0', '6', '0', '4', '2', '0', '1', '7'};

int counter = 0;      // counts number of digits of Serial number



// ----------- Collection of Subprograms for Keypad Game -------------- //


/* Accepts two char arrays with max length of 16.
   Prints out the message on the LCD display after
   deleting the previous text. */
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

/* Welcome Screen to introduce the user to the mobile escape game by MCBS.
   Start of Keypad Game. User is requested to enter the Serial number
   which is painted in red onto the back of the bomb. */
void LCDwelcomeScreen() {
  printOnLCD("Enter Serial Nr:", "   ===MCBS===");
}

void resetKeypad() {
  char keyword_in[_dimSerialNr] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  counter = 0;
  Serial.println(keyword_in);
}


/* Appears when input number series has been confirmed by the user,
   but the number of digits is not sufficient. */
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

/* Prints dots on LCD display to create more tension for the user
   while waiting for the result (after input has been confirmed). */
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

/* Appears when Keypad Game has been finished */
void LCDsolved() {
  KeypadFinished = 1;
}

/* Appears when input series has been entered and confirmed by the user
   but is not correct. */
void LCDwrong() {
  for (int i = 3; i >= 1; i--) {
    printOnLCD("Self-destruct in..", "");
    lcd.setCursor(0, 1);
    lcd.print(i);
    LCDdotting(1, 1);
  }

  printOnLCD("     ERROR:", "  PIN invalid!");
  delay(3000);
  printOnLCD("Time Penalty:", "  -30 sec");
  delay(3000);
}


/* This method is called when any number button (0 to 9) has been pressed by the user.
   Since it is called from the loop, it is evaluated every loop iteration. */
void keyPadCode(char key) {

  // key has been pressed
  if (key) {

    // delete last digit
    if (key == '#') {
      if (counter > 0) {
        counter -= 1;
        keyword_in[counter] = ' ';
        LCDpassword();
        return;
      }
    }

    // code has been confirmed
    if (key == '*') {
      if (counter == _dimSerialNr) {
        if (keyword_in[0] == keyword_set[0] and keyword_in[1] == keyword_set[1] and
            keyword_in[2] == keyword_set[2] and keyword_in[3] == keyword_set[3] and
            keyword_in[4] == keyword_set[4] and keyword_in[5] == keyword_set[5] and
            keyword_in[6] == keyword_set[6] and keyword_in[7] == keyword_set[7]) {

          Serial.println("You got the right Code");
          LCDcorrect();
          resetKeypad();
          LCDsolved();
          return;
        }
        if (keyword_in != keyword_set) {
          Serial.println("Your Code is WRONG");
          Serial.println("Your timeout is 300 seconds");
          LCDwrong();
          delay(3000);
          lcd.clear();
          resetKeypad();
          LCDwelcomeScreen();

          return; // need to reset counter to 0
        }
      }
      else {
        Serial.println("You have to press more numbers");
        LCDmoreNumbers();
        LCDpassword();
        return;

      }
    }

    // add one digit
    else {
      if (counter <= (_dimSerialNr - 1)) {
        keyword_in[counter] = key;
        LCDpassword();
        counter += 1;
      }

      Serial.println(key);
      Serial.println(counter);

      if (counter == _dimSerialNr) {
        LCDpassword();
        Serial.println("Press * for check password");
        Serial.println("Press # for delete last number");
        addToLCD(0, 1, "Press * Confirm");
      }
    }
  }
}


void keyPadGame() {


  char key = keypad1.getKey();
  keyPadCode(key);

}

void KeypadGamePinSetup() {

}
