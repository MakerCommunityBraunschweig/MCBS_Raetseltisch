
const byte ROWS_r = 1;
const byte COLS_r = 4;

char raetsel_keys[ROWS_r][COLS_r] = {
  {'1', '2', '3', '4'}
};


byte row_rPins[ROWS_r] = {45};
byte col_rPins[COLS_r] = {37, 38, 39, 40};

//Define the four buttons as a virtual keyboard object.
Keypad keypad3 = Keypad( makeKeymap(raetsel_keys), row_rPins, col_rPins, ROWS_r, COLS_r);


int LED_Pins[5] = {0, 41, 42, 43, 44};
int LED_Status[5] = {0, 0, 0, 0, 0};       // first element remains unused! => LED 1 represented by [1], ...
int answerSet[5] = {0, 3, 1, 2, 3};       // Correct Order of Answers: C // A // B // C
int QuizPoints = 0;

int QuizGameFinished = 0;
int QuizGameStarted = 0;


// ------ Methods used for control of the four button LEDs --------


/* Turn on the selected LED */
void turnOnLED(int LEDnum) {
    LED_Status[LEDnum] = 1;
    digitalWrite(LED_Pins[LEDnum], HIGH);
}

void turnOnAllLEDs() {
    for(int i = 1; i <= 4; i++) {
      LED_Status[i] = 1;
      digitalWrite(LED_Pins[i], HIGH);  
    }
    
}

/* Turn off the selected LED */
void turnOffLED(int LEDnum) {
    LED_Status[LEDnum] = 0;
    digitalWrite(LED_Pins[LEDnum], LOW);
}

void turnOffAllLEDs() {
    for(int i = 1; i <= 4; i++) {
      LED_Status[i] = 0;
      digitalWrite(LED_Pins[i], LOW);  
    }
}


void runningLight(int iter) {
  for(int j = 1; j <= iter; j++) {
    for(int i = 1; i <= 4; i++) {
      turnOnLED(i);
      delay(100); 
    }
    for(int i = 1; i <= 4; i++) {
      turnOffLED(i);
      delay(100); 
    } 
  }
}

void BlinkLED(int LEDnum) {
  for(int i = 1; i <= 3; i++) {
    turnOnLED(LEDnum);
    delay(200);
    turnOffLED(LEDnum);
    delay(200); 
  }
}

void BlinkAllLEDs() {
  for(int i = 1; i <= 3; i++) {
    turnOnAllLEDs();
    delay(200);
    turnOffAllLEDs();
    delay(200); 
  }
}


// =====================================================================================================


void ButtonPressedQuiz(char qg_input) {

  int taste = qg_input - 48;         // calculate integer value {1 2 3 4} from char array {'1' '2' '3' '4'}
  Serial.println(taste);

  if(taste == answerSet[QuizPoints + 1]) {
    QuizPoints += 1;
      turnOffAllLEDs();
    BlinkLED(answerSet[QuizPoints]);  
      turnOnAllLEDs();
    Serial.println("Correct answer");
    Serial.println(QuizPoints);  
    if(QuizPoints == 4) {
      QuizGameFinished = 1;
      turnOffAllLEDs();
      runningLight(3);
      Serial.println("Quiz solved successfully!");
    }
  }
  else {
    BlinkAllLEDs();
    turnOnAllLEDs();
    QuizPoints == 0;
    Serial.println("Wrong answer! Restart Quiz!");
  }
}

/* Quiz Game */
void QuizGame() {
  if (QuizGameStarted == 0){
    Serial.println("QuizGame() activated");
    QuizGameStarted = 1;
    runningLight(3); 
    turnOnAllLEDs();
  }
  char qg_input = keypad3.getKey();    
}

void QuizGamePinSetup() {
  
  // Green LEDs (4)
  for(int i = 41; i <= 44; i++){
    pinMode(i, OUTPUT);
  }

  // Metal Buttons (4)
  for(int i = 37; i <= 40; i++) {
    pinMode(i, INPUT);
  }
}







