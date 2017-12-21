#include "Arduino.h"
#define STARTCHAR 197
#define ENDCHAR 165

class ReceiveClass
{
private:
	char receiveBuffer[4];
public:
	ReceiveClass();
	
	int GetTrigger();
};
