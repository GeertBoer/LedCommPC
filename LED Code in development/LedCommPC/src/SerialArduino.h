#pragma once
#include "ofMain.h"
#include "ledColors.h"
#include <iostream>
#include <vector>

class SerialArduino
{
private:
	ofSerial serial;
	std::vector<ledColors> colorsToFlush;
	uint8_t amountOfColors = 0;
public:
	SerialArduino(char *port, int baud);
	bool SetColor(uint8_t num, uint8_t red, uint8_t green, uint8_t blue);
	bool SetColorV2(int num, uint8_t red, uint8_t green, uint8_t blue);
	bool FlushV2();
	bool Delay(uint16_t delay);
	bool Flush();
	bool Clear();
	~SerialArduino();
};

