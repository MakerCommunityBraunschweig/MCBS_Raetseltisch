#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Wire.h>

/*LCD setup*/
#define rs_pin 12
#define en_pin 11
#define d4_pin 5
#define d5_pin 4
#define d6_pin 3
#define d7_pin 2
LiquidCrystal lcd(rs_pin, en_pin, d4_pin, d5_pin, d6_pin, d7_pin);

/*Keypad setup*/
byte rowPins[ROWS] = {3, 2, 1, 0};//connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5};   //connect to the column pinouts of the keypad
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

/*Game setup*/
char output = 0;
int gamestatus = 0;
const byte pinLength = 8;
byte inputLength = 0;
const char pinCode[] = {"06042017"};
char keyBuffer[] = {"--------"} //savespave for input

void setup() {
  Serial.begin(9600);
  Wire.begin(3);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event
  printOnLCD("Standby- Modus", "");
}

void loop() {
  if (gamestatus == 1 ) {
    printOnLCD("Seriennummer:   ", "");
    char customKey = customKeypad.getKey();
    if (customKey) {
      // Check, ob ASCII Wert des Char einer Ziffer zwischen 0 und 9 entspricht
      if ((int(customKey) >= 48) && (int(customKey) <= 57) && (inputLength <= pinLength)) {
        keyBuffer[inputLength] = customKey;
        inputLength++;
      }
      // oder Code überprüfen, falls Raute gedrückt wurde
      else if (customKey == '#') {
        checkPin();
      }
      else if ((customKey == '*') &&
      (inputLength > 0 ) {
      keyBuffer[inputLength] = '-';
        inputLength--;
      }
    }
  }
}
