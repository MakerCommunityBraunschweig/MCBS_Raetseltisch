#include <Buzzer.h>
#include <Wire.h>
#include <TM1637.h>

//Gamesettings
const byte   penalty = 30;
const short  gametime = 300;

/*
   Beschreibung der Stages:
    Stage | Beschreibung

    0     | Standby - warte auf Start durch Startknopf
    1     | Spiel 1
    2     | Spiel 2
    3     | Spiel 3
    4     | Spiel 4
    5     | Spiel gewonnen
    6     | Spiel verloren
    7     | Standby - warte auf Reset
*/



//Pin- Setup
#define CLK 2
#define DIO 3
#define startbutton  4
#define reset_button 6
#define cheatbutton 7
#define buzzerPin   5

TM1637 tm1637(CLK, DIO);      // create timer object with correct pin numbers
Buzzer buzzer(buzzerPin);

//game-intern variables
byte stage = 0;
char recievedData = 0;
int timer = gametime;         //gametime
unsigned long starttime = 0;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Wire.begin(99);        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(startbutton, INPUT_PULLUP);
  pinMode(reset_button, INPUT_PULLUP);
  pinMode(cheatbutton, INPUT_PULLUP);
  //animationFC() ;
  //animationStartup();
  // ------------------- Timer for SevSeg Display ------------------------
  tm1637.init();
  tm1637.set(BRIGHTEST);                // BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  tm1637.point(POINT_ON);
  reset();
}

void loop() {
  if (digitalRead(cheatbutton) == LOW) {
    stage++;
    if (stage <= 4) {
      Wire.beginTransmission(stage);  // transmit to device
      Wire.write('a');                // activate next game
      Wire.endTransmission();         // stop transmitting
      Serial.println("aktiviere nächstes Modul");
    }
    Serial.println("Du Cheater!");
    delay(1000);
  }
  switch (stage) {
    //Standby
    case 0:
      if (digitalRead(startbutton) == LOW) {
        Serial.println("Spiel gestartet");
        starttime = millis();
        stage++;
        Wire.beginTransmission(1);  // transmit to device
        char output = 'a';
        Wire.write(output);                // activate next game
        delay(25);
        Wire.endTransmission();         // stop transmitting
        Serial.println("aktiviere erstes Modul");
        //fancy startanimation + sound
      }
      break;
    //Win
    case 5:
      win();
      stage = 7;
      break;

    //Game Over
    case 6:
      fail();
      stage = 7;
      break;
    //
    case 7:
      wait_for_reset();
      break;

    default:
      updateTimer();
      Wire.requestFrom(stage, 1);     // request 1 bytes from slave device #stage
      while (Wire.available()) {      // slave may send less than requested
        recievedData = Wire.read();              // receive a byte as character
      }
      switch (recievedData) {
        //next stage has been activated
        case 'a':
          Serial.println("Modul aktiviert.");
          break;
        //mistake has been made
        case 'f':
          Serial.println("Fehler! Zeitstrafe");
          if (timer - penalty < 0) {
            stage = 6;
            timer = 0;
            showTime();
          }
          else {
            timer = timer - penalty;
            updateTimer();
            buzzer.begin(50);
            buzzer.sound(NOTE_C4, 100);
            buzzer.sound(NOTE_C3, 200);
          }
          break;
        //stage has been solved
        case 's':
          Serial.println("Modul gelöst");
          stage++;
          if (stage <= 4) {
            Wire.beginTransmission(stage);  // transmit to device
            Wire.write('a');                // activate next game
            Wire.endTransmission();         // stop transmitting
            Serial.println("aktiviere nächstes Modul");
          }
          break;
      }
  }
}
