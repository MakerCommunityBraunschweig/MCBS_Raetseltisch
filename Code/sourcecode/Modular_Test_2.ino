
/*  *********** Mobile Escape Game *************               
 *   
 *  Made by Maker Community Braunschweig (MCBS)
 *  
 *  
 *  Authors: Rudolph Leue
 *           Martin Dehmel
 *           ...
   
    Editing History:
    V0.1    12.03.2017 Keypad
    V0.2    01.04.2017 BarGame
    V0.2.1  05.04.2017 Keypad fixed
    V0.3    19.04.2017 Games added
    V0.3.1  19.04.2017 Countdown added
    V0.4    16.06.2017 Checkpoints in Functions added
    V0.5    11.08.2017 SoftwareVersion als Stamp hinzugefügt, Zeitlayout angepasst
                       correctSequencing Funktion hinzugefügt
    V0.5.1  13.08.2017 Überarbeitung BarGame, Änderung der Buttoninputs mit internem Pullup
    V0.5.2  20.10.1017 Änderung des define sensorOut von A2 in Arduino Pin 56/ Verifikation ausstehend!
    V0.6    21.10.2017 Neuprogrammierung BarGame, Umbenennung Keypad in Keypad1
    V0.7    06.11.1017 Änderung des BarGames in Matrix, Hinzufügen der Kontrollstrukturen, Setzen des Checkpoints ausstehend!! Z475
    V0.7.1  11.11.2017 Änderung der Deklaration der LEDs des BarGames, LED Feedback hinzugefügt
    V0.8    09.02.2018 Änderung des Rätselspiels in Matrix
    V0.9    24.05.2018 Keypad works! Keypad related methods shifted to 'Keypad.h'

*/

#include <Keypad.h>
#include <LiquidCrystal.h>

#include "KeypadGame.h"
#include "ColourCards.h"
#include "QuizGame.h"
#include "BarGame.h"
#include "Timer.h"


/* The game is controlled via a game status variable. 
 * Meaning of the values: 
 * 0: General Control Mode
 * 1: Colour Cards
 * 2: Quiz Game
 * 3: Keypad Game
 * 4: Bar Game       
 */

unsigned int GameStatus = 0;


// ----------------- Hardware Setup ------------------- //


void setup() {
   
   Serial.begin(9600);

  // -------------------- Station 1: KeypadGame ------------------------------
  keypad1.addEventListener(KeypadGameEvent);
  KeypadGamePinSetup();

  lcd.begin(16, 2);                                  // Activate 16 x 2 LCD display
  
  
  // -------------------- Station 2: ColourCards ------------------------------
  ColourCardsPinSetup();

  //-------------------- Station 3: QuizGame ------------------------------
  keypad3.addEventListener(QuizGameEvent); //Add Event Listener for QuizGame

  QuizGamePinSetup();

  //-------------------- Station 4: BarGame ------------------------------
  keypad4.addEventListener(BarGameEvent); //Add Event Listener for BarGame

  BarGamePinSetup();


  // ------------------- Timer for SevSeg Display ------------------------
  tm1637.init();
  tm1637.set(BRIGHTEST);      // BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

  
  int countDir = DOWN;              // Set counting direction

  unsigned long initialTime = millis();   // Create time variable

  showTime(minutes,seconds);

}

// Main loop, in control of game.

void loop() {

  // Update the timer
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;    
    decreaseTime(1);
    showTime(minutes, seconds);
  }

  
  switch(GameStatus) {
    // General Control Mode
    case 0:
      printOnLCD(" Start the Game","   ===MCBS===");
      delay(5000);
      GameStatus += 1;
      printOnLCD("Aktuelle Station","Colour Cards");
    break;
    case 1:
      colourCards();
      if (ColourCardsFinished) {
        GameStatus += 1;
        printOnLCD("Aktuelle Station","Quiz Game");
      }
    break;
    case 2:
      QuizGame();
      if (QuizGameFinished) {
        GameStatus += 1;
        printOnLCD("Aktuelle Station","Keypad Game");
        delay(2000);
        LCDwelcomeScreen();                                // Show welcome Screen for Keypad Game
      }
    break;
    case 3:
      keyPadGame();
      if (KeypadFinished) {
        GameStatus += 1;
        printOnLCD("Aktuelle Station","Bar Game");
      }
    break;
    case 4:
      BarGame();
      if (BarGameFinished) {
        GameStatus = 0;
        endOfGame();
      }
    break;
    
  }

}

// Taking care of some events.

void KeypadGameEvent(KeypadEvent key) {                      // Taste auf keypad1 gedrückt

  switch (keypad1.getState()) {                          // Status der Taste abfragen
    case PRESSED:
      // keyPressed(key);
    break;
  }
  
}

void QuizGameEvent(KeypadEvent qg_input){
  
  switch (keypad3.getState()){
    case PRESSED:
      Serial.println("Button pressed");
      ButtonPressedQuiz(qg_input);
  }
}

void BarGameEvent(KeypadEvent bg_input) {

  switch (keypad4.getState()) {
    case PRESSED:
      if (bg_input == 'X') {         // Red Button has been pressed
        Serial.println("Red button pressed");
        showSequence();               // Sequence of green LEDs is shown
        redButtonCounter +=1;
        break;
      }

      if( redButtonCounter >= 0 ) {

        if (bg_input == BarGameSequence[(correctBarsCounter)]){      // Pulled bar was correct!
          BGInputSequence[(correctBarsCounter)] = bg_input;
          Serial.println("Correct");
          correctSequencing((int(bg_input)-49));
          correctBarsCounter += 1;
        } else {                                                     // Pulled bar was wrong!
          falseSequencing();
          Serial.println("Wrong");
          resetBarGame();
        }

        if (correctBarsCounter == 5) {                                // Sequence was correct!
          BarGameFinished = 1;
          finalBGSequence();
        }
        
      }
      
  }
}


//-------------------- End of Game --------------------------------

void endOfGame() {
  printOnLCD("  Gratulation! ","  Spiel beendet");
}


