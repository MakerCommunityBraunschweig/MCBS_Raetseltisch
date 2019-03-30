
// Timer definition

#include "TM1637.h"         // Timer Library

#define CLK 51                //pins definitions for TM1637 and can be changed to other ports
#define DIO 50
#define UP 1                  // abbreviations for counting directions are defined
#define DOWN -1

TM1637 tm1637(CLK, DIO);      // create timer object with correct pin numbers

int minutes = 5;                  // Set initial time values for counter
int seconds = 0;
long previousMillis = 0;
long interval = 1000;

void showTimeSerial(int a, int b, int c, int d) {
  Serial.print(a);
  Serial.print(b);
  Serial.print(':');
  Serial.print(c);
  Serial.print(d);
  Serial.print('\n');
}

void showTime(int minutes, int seconds) {

  int d = seconds % 10;                 // Calculate 4 separate digits: [a b : c d]
  int c = (seconds - d) / 10;
  int b = minutes % 10;
  int a = (minutes - b) / 10;

  //showTimeSerial(a,b,c,d);              // Show time on serial monitor:  ab:cd

  tm1637.display(0, a);                 // Show new time on display
  tm1637.display(1, b);
  tm1637.display(2, c);
  tm1637.display(3, d);
}

/* Decreases the timer value by n seconds! */
void decreaseTime(int n) {
  seconds -= n;
  if (seconds < 0) {
    minutes--;
    seconds += 60;
  }
  if (minutes < 0) {
    minutes = 0;
  }
}

/* Increases the timer value by n seconds! */
void increaseTime(int n) {
  seconds += n;
  if (seconds >= 60) {
    minutes++;
    seconds -= 60;
  }
}
