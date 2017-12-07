#include "SerialArduino.h"

SerialArduino::SerialArduino(char *port, int baud)
{
	if (!serial.setup(port, baud))
	{
		throw 20; // :/
	}
}

bool SerialArduino::SetColor(uint8_t num, uint8_t red, uint8_t green, uint8_t blue)
{
	unsigned char buf[7] = { '#', '1', num, red, green, blue, '%' };
	serial.writeBytes(buf, 7);
	return true;
}

bool SerialArduino::Flush()
{
	unsigned char buf[3] = { '#', '2', '%' };
	serial.writeBytes(buf, 3);
	return true;
}

SerialArduino::~SerialArduino()
{
	serial.close();
}
