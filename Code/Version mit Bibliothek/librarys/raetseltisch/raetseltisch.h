/*
  raetseltisch.cpp - Rätseltisch- Bibliothek der Maker Community Braunschweig.
  Created by Tim Kessel, June 23, 2019.
*/

#ifndef raetseltisch_h
#define raetseltisch_h

#include <Arduino.h>

class module{
  public:
	module(int I2C_adress, int* resetarray);
	void begin();
	static void requestEvent();
	static void receiveEvent(int howMany);
    static void solved();
    static void fail();
    static void activated();
    static void reset();
	void set_gamestatus(int i);
	void increase_gamestatus();
    
  private:
	int gamestatus = 0;
	char output;
    int I2C_adress;
	int* resetarray = 0;
	int* savearray = 0;
};

class master{
  public:
	master(int I2C_adress);
	void set_gametime(int seconds);
	void set_penalty(int seconds);
	void increase_stage();
	void set_stage(int i);
    void win();
    void game_over();
    void reset();
    
  private:
	int gametime;
	int penalty;
	int stage;
	int interval;
	int timer;
	int* resetarray;
	int []savearray;
	unsigned long starttime = 0;
	unsigned long previousMillis = 0;
	unsigned long previousMillis2 = 0;
	
    
};
#endif