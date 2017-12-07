#pragma once
#include "ofMain.h"

class SerialArduino
{
private:
	ofSerial serial;
public:
	SerialArduino(char *port, int baud);
	bool SetColor(uint8_t num, uint8_t red, uint8_t green, uint8_t blue);
	bool Flush();
	~SerialArduino();
};

