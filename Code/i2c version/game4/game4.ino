#include <Wire.h>

#define startbutton A1
const byte button[]     = {0, 2, 3, 4, 5};
const byte red_Led[]    = {0, 6, 8, 10, 12};
const byte green_Led[]  = {0, 7, 9, 11, 13};

//Arraylänge gibt Anzahl der zu merkenden Lampen vor
byte sequence[5];

byte input[sizeof(sequence)];
byte input_length = 0;
char output = 0;
byte gamestatus = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialisiere...");
  Wire.begin(4);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event

  //Pin- Setup
  pinMode(startbutton, INPUT_PULLUP);
  for ( int i = 1; i <= 4; i++) {
    pinMode(button[i], INPUT_PULLUP);
    pinMode(red_Led[i], OUTPUT);
    pinMode(green_Led[i], OUTPUT);
  }
  //Generiere zufällige Sequenz und mache Spiel bereit
  reset();
  Serial.println("Spiel initialisiert.\n");
}

void loop() {
  //warte bis Spiel gestartet wird
  if (gamestatus > 0) {

    //Spiele Sequenz ab und fordere danach die Eingabe
    if (digitalRead(startbutton) == HIGH && gamestatus == 1) {
      blinkSequence();
      progress();
    }

    //Wenn Sequenz abgespielt wurde, erwarte Eingabe
    if ( gamestatus == 2) {
      byte pressed_button = get_button();

      //speichere gedrückten Knopf im array, um am Ende zu vergleichen
      if (pressed_button > 0) {
        input[input_length] = pressed_button;
        input_length++;
        digitalWrite(green_Led[pressed_button], HIGH);
        delay(200);
        digitalWrite(green_Led[pressed_button], LOW);
        delay(50);
      }

      //Vergleiche Input mit geforderter Sequenz
      if (input_length == sizeof(sequence)) {
        if (array_comp(sequence, input) == true) {
          win();
        }
        else {
          fail();
        }
      }
    }
  }
}
