#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Wire.h>

/*LCD setup*/
#define rs_pin 2
#define en_pin 3
#define d4_pin 4
#define d5_pin 5
#define d6_pin 6
#define d7_pin 7
LiquidCrystal lcd(rs_pin, en_pin, d4_pin, d5_pin, d6_pin, d7_pin);

/*Keypad setup*/
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
byte rowPins[ROWS] = {9, 10, 11, 12};//connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, A2, A3};   //connect to the column pinouts of the keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

/*Game setup*/
char output = 0;
int gamestatus = 1;
const byte pin_length = 8;
byte input_length = 0;
const char pin_code[] = {"06042017"};
char input[sizeof(pin_code)];

void setup() {
  Serial.begin(9600);
  Wire.begin(3);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event
  printOnLCD("Standby- Modus", "");
  reset();
}

void loop() {
  if (gamestatus == 1 ) {
    printOnLCD("Seriennummer:   ", "");
    char customKey = customKeypad.getKey();
    if (customKey) {
      // Check, ob ASCII Wert des Char einer Ziffer zwischen 0 und 9 entspricht
      if ((int(customKey) >= 48) && (int(customKey) <= 57) && (input_length <= pin_length)) {
        input[input_length] = customKey;
        input_length++;
      }
      // oder Code überprüfen, falls Raute gedrückt wurde
      else if (customKey == '#') {
        checkPin();
      }
      else if (customKey == '*' && input_length > 0 ) {
        input[input_length] = '-';
        input_length--;
      }
    }
  }
}
