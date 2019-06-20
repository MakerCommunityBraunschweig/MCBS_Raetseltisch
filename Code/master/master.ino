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
#define startbutton  8
#define cheatbutton 11
#define buzzerPin   5
#define piepton NOTE_C7

TM1637 tm1637(CLK, DIO);      // create timer object with correct pin numbers
Buzzer buzzer(buzzerPin);

//game-intern variables
byte stage = 0;
int timer = gametime;
int interval = 1000;
unsigned long starttime = 0;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;

void setup() {
  Wire.begin(100);
  Serial.begin(9600);
  Serial.println("initiating startup");
  pinMode(startbutton, INPUT_PULLUP);
  pinMode(cheatbutton, INPUT_PULLUP);
  tm1637.init();
  tm1637.set(BRIGHTEST);
  tm1637.point(POINT_ON);
  reset();
  animation_startup();
  Serial.println("startup complete");
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
    
    case 0:
          //Standby
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
    
    case 5:
          win();
          stage = 7;
          break;

    case 6:
          game_over();
          stage = 7;
          break;

    case 7:
          wait_for_reset();
          break;

    default:
          if (update_timer() == true) {
            update_display();
            serial_print_time();
          }
          beep();
          Wire.requestFrom(stage, 1);     // request 1 bytes from slave device #stage
          char recievedData;
          while (Wire.available()) recievedData = Wire.read();              // receive a byte as character
          
          switch (recievedData) {
    
            case 'a':
                  //next stage has been activated
                  Serial.println("Modul aktiviert.");
                  break;
    
            case 'f':
                  //mistake has been made
                  Serial.println("Fehler! Zeitstrafe");
                  timer = timer - penalty;
                  buzzer.begin(50);
                  buzzer.sound(NOTE_C6, 100);
                  buzzer.sound(NOTE_C5, 200);
                  break;
    
            case 's':
                  //stage has been solved
                  Serial.println("Modul gelöst");
                  stage++;
                  buzzer.begin(50);
                  buzzer.sound(NOTE_C5, 100);
                  buzzer.sound(NOTE_C6, 200);
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
