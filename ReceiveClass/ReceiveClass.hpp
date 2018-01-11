#include "Arduino.h"
#define STARTCHAR 197
#define ENDCHAR 165

class ReceiveClass
{
private:
	char receiveBuffer[4];
public:
	ReceiveClass();
	int GetTrigger(); //returns step number which is being triggered, or -1 if no trigger.
};
