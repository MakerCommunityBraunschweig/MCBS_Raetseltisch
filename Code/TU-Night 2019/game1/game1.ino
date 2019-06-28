#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
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

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
//--------------------Station colourCards------------------------------
char output = 0; //Diese Variable wird immer an den Master gesendet und enthält die notwendige Information über den Zustand des Moduls
byte gamestatus = 0; // Interne Variable zur Steuerung des Spielablaufes
const byte UID1[] = {41, 24, 150, 38};  //RFID Identifikationsnummern der verschiedenen Ausweiskarten:
const byte UID2[] = {41, 226, 205, 39};
const byte UID3[] = {137, 29, 31, 86};

void setup() {
  Serial.begin(9600);
  Serial.println("Initialisiere...");
  SPI.begin(); // Init SPI bus
  Wire.begin(1);                // Lege Adresse und somit Reinfolge der Module fest (Adrese 1 = erstes Modul)
  Wire.onRequest(requestEvent); // Definiere welche Funktion aufgerufen werden soll, wenn der Master daten anfragt
  Wire.onReceive(receiveEvent); // Definiere welche Funktion aufgerufen werden soll, wenn der Master Daten sendet

  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(progressLED1, OUTPUT);
  pinMode(progressLED2, OUTPUT);
  pinMode(progressLED3, OUTPUT);

  rfid.PCD_Init(); // Initialisiere das RFID Lesegerät
  reset(); // rufe die Resetfunktion auf um sicherzugehen, dass alles funktioniert
  Serial.println("Initialisierung abgeschlossen.");
}

void loop() {
  if (gamestatus > 0 && gamestatus < 5) { // warte darauf, dass der gamestatus durch die "recieveEvent"-Funktion erhöht wird
     byte cardnumber = getCardnumber();   
    if (cardnumber == gamestatus && gamestatus < 4 && cardnumber > 0) { // wenn die Nummer der Karte die Richtige ist, erwarte die Karte mit der nächstgrößeren NUmmer
      progress(); // erhöhe gamestatus um 1
    }
    else if (cardnumber != gamestatus && gamestatus < 4 && cardnumber > 0) { // wenn karte falsch ist
      fail(); // gehe wieder auf gamestatus 1 und erwarte die erste Karte
    }
    else if ( gamestatus == 4) { // wenn alle drei Karten in der richtigen Reinfolge gelesen wurden
      win();
    }
  }
  updateProgressLed(); //Aktualisiere den Fortschrittsindikator (Led's auf dem Modul)
}
