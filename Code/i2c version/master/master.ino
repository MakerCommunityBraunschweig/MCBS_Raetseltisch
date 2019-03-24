#include <Buzzer.h>
#include <Wire.h>
#include <TM1637.h>

//Gamesettings
const int   penalty = 30;
const int   gametime = 300;

//TM1637 pins
#define CLK 2
#define DIO 3

//startbutton
#define startbutton 5

//buzzer pin
#define buzzerPin   6

TM1637 tm1637(CLK,DIO);       // create timer object with correct pin numbers
Buzzer buzzer(buzzerPin);

//game-intern variables
int   starttime = 0;
int   stage = 0;
char  recievedData = 0;
int   timer = gametime;         //gametime
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  pinMode(startbutton, INPUT_PULLUP);
  animationStartup();
  
  // ------------------- Timer for SevSeg Display ------------------------
  tm1637.init();
  tm1637.set(BRIGHTEST);                // BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  tm1637.point(POINT_ON);
  gameReset();
}

void loop() {
  switch (stage){
    //Standby
    case 0:   
              if (digitalRead(startbutton)==LOW){
                Serial.println("Spiel gestartet");
                starttime = millis();
                stage++;
                //fancy startanimation + sound
              }
              break;
    //Win
    case 5:   
              animationWin();
              Serial.println("Gewonnen!");
              Serial.print("Spielzeit: ");
              Serial.println((300000 - previousMillis)/1000);
              //fancy action sequenz, SPIELENDE
              break;

    //Game Over
    case 6:   
              Serial.println("Game over!");
              animationGameOver();
              delay(5000);
              gameReset();
              break;
    //
    default:  
              updateTimer();
              Wire.requestFrom(1, stage);     // request 1 bytes from slave device #stage
              while (Wire.available()) {      // slave may send less than requested
                recievedData = Wire.read();              // receive a byte as character
              }
              switch (recievedData){
                //next stage has been activated
                case 'a': 
                          Serial.println("Modul aktiviert.");
                          break;
                //mistake has been made          
                case 'f': 
                          Serial.println("Fehler! Zeitstrafe");
                          if (timer - penalty < 0){
                            stage = 6;
                            timer = 0;
                            showTime();
                          }
                          else {
                            timer = timer - penalty;
                            updateTimer();
                            buzzer.begin(50);
                            buzzer.sound(NOTE_C4,100);
                            buzzer.sound(NOTE_C4,100);
                          }
                          break;
                //stage has been solved
                case 's': 
                          Serial.println("Modul gelöst");
                          Wire.beginTransmission(++stage);  // transmit to device
                          Wire.write('a');                // activate next game
                          Wire.endTransmission();         // stop transmitting
                          break;
              }
    }
}
