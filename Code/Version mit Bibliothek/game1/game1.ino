#include <raetseltisch.h>
#include <SPI.h>
#include <MFRC522.h>

/*
  SCK  13
  MISO 12
  MOSI 11
  SDA  10
  RST  9
*/
#define rLED 7
#define gLED 8
#define progressLED1 2
#define progressLED2 3
#define progressLED3 4
#define SS_PIN 10
#define RST_PIN 9


int Speicherarray[]= {1, 2, 3, 4};

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
module modul(1, Speicherarray);
//--------------------Station colourCards------------------------------

const byte UID1[] = {41, 24, 150, 38};
const byte UID2[] = {41, 226, 205, 39};
const byte UID3[] = {137, 29, 31, 86};

void setup() {
  modul.begin();
  Serial.println("Initialisiere...");
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(progressLED1, OUTPUT);
  pinMode(progressLED2, OUTPUT);
  pinMode(progressLED3, OUTPUT);

  module::reset();

  Serial.println("Initialisierung abgeschlossen.");
}

void loop() {
  if (modul.get_gamestatus() > 0 && modul.get_gamestatus() < 5) {
     byte cardnumber = getCardnumber();
    if (cardnumber == modul.get_gamestatus() && modul.get_gamestatus() < 4 && cardnumber > 0) {
      modul.increase_gamestatus();
      animation_fail();
    }
    else if (cardnumber != modul.get_gamestatus() && modul.get_gamestatus() < 4 && cardnumber > 0) {
      module::fail();
      animation_fail();
    }
    else if ( modul.get_gamestatus() == 4) {
      module::solved();
      animation_solved();
    }
  }
  updateProgressLed();
}
