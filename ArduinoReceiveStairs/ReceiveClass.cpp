#include "ReceiveClass.hpp"

ReceiveClass::ReceiveClass()
{
	Serial.begin(9600);
}

int ReceiveClass::GetTrigger()
{
	if (Serial.available() >= 3)
	{
		Serial.readBytes(receiveBuffer, 3);

		if ((receiveBuffer[0] == STARTCHAR) && (receiveBuffer[2] == ENDCHAR))
		{
			for (int i = 0; i < 8; i++)
			{
				if ((receiveBuffer[1] >> i) & 0x01)
				{
					return i;
				}
			}
		}
	}	
	return -1;
}
