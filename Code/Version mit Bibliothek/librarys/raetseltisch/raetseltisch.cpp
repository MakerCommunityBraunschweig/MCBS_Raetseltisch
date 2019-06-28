/*
  raetseltisch.cpp - Rätseltisch- Bibliothek der Maker Community Braunschweig.
  Created by Tim Kessel, June 23, 2019.
*/
#include "raetseltisch.h"
#include <Arduino.h>
#include <Wire.h>

module::module(int I2C_adress, int *resetarray){
	this->I2C_adress = I2C_adress;				//speichere I2C Adresse
	this->resetarray = resetarray;				//speichere Adresse des zu verwendenen Arrays
	savearray = new int[sizeof(resetarray)] 	//ersetelle Kopie des Arrays um Original bei
	for(int i; i < sizeof(resetarray); i++){	//Reset wiederherstellen zu können
		savearray[i] = resetarray[i];			//
	}											//
	
}

void module::begin(){
	Serial.begin(9600);
	Wire.begin(I2C_adress);
	Wire.onRequest(module::requestEvent); // register event
	Wire.onReceive(module::receiveEvent); // register event
}

void module:: requestEvent() {
  Wire.write(output); // respond with message of 1 bytes
  output = 'o';       // overwrite sent data with something else to avoid sending the same data twice
}

void module:: receiveEvent(int howMany) {
  while (1 <= Wire.available()) {// loop through all but the last
    char input = Wire.read();   // receive byte as a character
    Serial.print("Empfangende Daten: ");
    Serial.println(input);        // print the character
    switch  (input) {
      case 'a':
        gamestatus = 1;         //start the game
        module::activated();
        Serial.println("Das Modul wurde aktiviert");
        break;

      case 'r':                 //reset the game
        module::reset();
        break;

      default:
        Serial.print("Ungültiger Input: ");
        Serial.println(input);
    }
  }
}

void module:: solved(){
	output = 's';
	increase_gamestatus();
	Serial.println("Modul wurde gelöst.");
}

void module:: fail(){
	output = 'f';
	set_gamestatus(1);
	Serial.println("Es wurde ein Fehler gemacht.");
}

void module::activated(){
	output = 'a'
}

void module::reset(){
	set_gamestatus(0);
	for(int i; i < sizeof(resetarray); i++){
	*resetarray[i] = *savearray[i];
	}
}

void module::set_gamestatus(int i){
	gamestatus = i;
}

void module::increase_gamestatus(){
	gamestatus++;
}