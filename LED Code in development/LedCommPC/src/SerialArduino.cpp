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
	unsigned char bufIn[4];
	memset(bufIn, 0, 4);
	
	while ((bufIn[0] != '#') || (bufIn[1] != 'A') || (bufIn[2] != '1') || (bufIn[3] =! '%'))
	{
		serial.flush(true, true);
		serial.writeBytes(buf, 7);
		while (!(serial.available() >= 4)) {} //wait
		serial.readBytes(bufIn, 4);
	}
	
	return true;
}

bool SerialArduino::SetColorV2(int num, uint8_t red, uint8_t green, uint8_t blue)
{
	ledColors color;
	color.red = red;
	color.green = green;
	color.blue = blue;
	color.nPixel = num;

	colorsToFlush.push_back(color);
	amountOfColors++;

	return true;
}

bool SerialArduino::FlushV2()
{
	uint8_t nLeds1 = (amountOfColors & 0x003F);
	uint8_t nLeds2 = (amountOfColors >> 6);

	uint8_t buf[5] = { '#', '5', nLeds1, nLeds1 };
	serial.writeBytes(buf, 4);
	uint8_t nPixel1 = 0;
	uint8_t nPixel2 = 0;

	for (int i = 0; i < amountOfColors; i++)
	{
		nPixel1 = colorsToFlush[i].nPixel & 0x3F;
		nPixel2 = (colorsToFlush[i].nPixel >> 6) & 0x3F;
		buf[0] = nPixel1;
		buf[1] = nPixel2;
		buf[2] = colorsToFlush[i].red;
		buf[3] = colorsToFlush[i].green;
		buf[4] = colorsToFlush[i].blue;
		std::cout << "yowe1: " << (int)buf[0] << std::endl;
		serial.writeBytes(buf, 5);
	}

	serial.writeByte('%');
	colorsToFlush.clear();
	amountOfColors = 0;
	return true;
}

bool SerialArduino::Delay(uint16_t delay)
{
	uint8_t delay1 = (delay & 0x00FF);
	uint8_t delay2 = ((delay >> 8) & 0x00FF);
	unsigned char buf[5] = { '#', '4', delay1, delay2, '%' };
	serial.writeBytes(buf, 5);

	return true;
}

bool SerialArduino::Flush()
{
	unsigned char buf[3] = { '#', '2', '%' };
	unsigned char bufIn[3];
	memset(bufIn, 0, 3);

	while ((bufIn[0] != '#') || (bufIn[1] != '2') || (bufIn[2] != '%'))
	{
		serial.flush(true, true);
		serial.writeBytes(buf, 3);
		while (!(serial.available() >= 3)) {} //wait
		serial.readBytes(bufIn, 3);
	}

	return true;
}

bool SerialArduino::Clear()
{
	unsigned char buf[3] = { '#', '6', '%' };
	serial.writeBytes(buf, 3);
	return true;
}

SerialArduino::~SerialArduino()
{
	serial.close();
}
