
#define _BGSequenceLength 5                                                 // Length of LED sequence for Bar Game


// ================ DEFINE KEYPAD SECTION ===============
const byte ROWS_s = 1;
const byte COLS_s = 5;

char Bar_keys[ROWS_s][COLS_s] = {
  {'X', '1', '2', '3', '4'}
};

byte row_sPins[ROWS_s] = {36};
byte col_sPins[COLS_s] = {55, 23, 24, 25, 26};

Keypad keypad4 = Keypad( makeKeymap(Bar_keys), row_sPins, col_sPins, ROWS_s, COLS_s );

// =======================================================

char BGInputSequence[_BGSequenceLength] = {' ', ' ', ' ', ' ', ' '};               // Array for input sequence, generated by pulling up the bars in a certain order
char BarGameSequence[_BGSequenceLength] = {'3', '1', '2', '4', '2'};               // LED Sequence that is shown (Solution to this game)
int intBarGameSequence[5] = {3, 1, 2, 4, 2};                                       // *** can be replaced by generateBarSequence() ***

int correctBarsCounter = 0;                                                        // counts the number of correct bars pulled up according to the sequence

int BarGameStarted = 0;

int redButtonCounter = 0;                                                          // counts the number of times the Red Button has been pressed


int redleds[4] = {15, 17, 19, 21};                                                 // sets Arduino pins for red LEDs
int greenleds[4] = {16, 18, 20, 22};                                               // sets Arduino pins for green LEDs    


int BarGameFinished = 0;

// Methods used for BarGame

/* When the Red Button is pressed, a 'quiz sequence' is shown by the green LEDs.
   This series is to be remembered by the user and reproduced by pulling up the bars of that station
   in the correct order. */
void showSequence() {
  for (int i = 0; i <= 4; i++){
    digitalWrite(greenleds[intBarGameSequence[i]-1], HIGH);
    delay(300);
    digitalWrite(greenleds[intBarGameSequence[i]-1], LOW);
    delay(100);
  }
}

/* Turn on the selected LED */
void activateRedLED(int LEDnum) {
    Serial.println("RED on");
    digitalWrite(redleds[LEDnum-1], HIGH);
    
}

/* Turn on the selected LED */
void activateGreenLED(int LEDnum) {
    digitalWrite(greenleds[LEDnum-1], HIGH);
}


void BarGame() {

  if (BarGameStarted == 0){
    Serial.println("BarGame() activated");
    BarGameStarted = 1; 
  }
  
  char bg_input = keypad4.getKey();

  if (bg_input) {
    Serial.println(bg_input);
  }
  
}


/* Appears if the chosen bar was wrong.  */
void falseSequencing() {

  for (int i = 0; i <= 4; i++){
    for(int j = 0; j <= 3; j++) {
      digitalWrite(redleds[j], HIGH);
    }
    delay(300);
    for(int j = 0; j <= 3; j++) {
      digitalWrite(redleds[j], LOW);
    }
    delay(100);
  }

}

/* Appears if the chosen bar was correct. */
void correctSequencing(int A) {
  
  for (int i = 0; i <= 1; i++){
    digitalWrite(greenleds[A], HIGH);
    delay(1000);
    digitalWrite(greenleds[A], LOW);
  }
}



/* If a wrong bar was chosen, the Bar Game is set to initial state. */
void resetBarGame() {
  for (unsigned int i = 0; i < _BGSequenceLength; i++) {
    BGInputSequence[i] = ' ';
  }
  correctBarsCounter = 0;
}

/* Appears when the BarGame has been comleteted successfully. */
void finalBGSequence() {
  for (int j = 1; j <= 5; j++) {
    for (int i = 0; i <= 4; i++){
      digitalWrite(greenleds[intBarGameSequence[i]-1], HIGH);
    }
    delay(500);
    for (int i = 0; i <= 4; i++){
      digitalWrite(greenleds[intBarGameSequence[i]-1], LOW);
    }
    delay(200); 
  } 
}


void generateBarSequence(int slength) {
  
  int outputSequence[slength];
  for (int i = 0; i <= slength-1; i++){
    outputSequence[i] = random(1,5);
  }
  
}

void BarGamePinSetup() {

  // Red and Green LED Pins (8)
  for(int i = 15; i<= 22; i++) {
    pinMode(i,OUTPUT);
  }
  // Red Button
  //pinMode(53, INPUT);
  
}

