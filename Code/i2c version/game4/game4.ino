#include <Wire.h>

#define button1 4
#define button2 5

char output = 0;
int gamestatus = 0;


void setup() {
  Serial.begin(9600);
  Wire.begin(4);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Wire.onReceive(receiveEvent); // register event
  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  //Serial.println(output);
  if(digitalRead(button1) == LOW){
    output = 'a';
  }
  else if (digitalRead(button2) == LOW){
    output = 'f';
  }
  else{
    output = 'o';
  }
}

void requestEvent() {
  Wire.write(output); // respond with message of 6 bytes
  // as expected by master
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char input = Wire.read(); // receive byte as a character
    Serial.print(input);         // print the character
  }
}
