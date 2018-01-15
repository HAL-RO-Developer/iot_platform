#include "arduino.h"
#include "DeviceControl.h"


void Digital::SetMode(int pin, int mode)
{
	pinMode(pin, mode);
}

void Digital::Write(int pin, int value)
{
	digitalWrite(pin, value);
}

int Digital::Read(int pin)
{
	return digitalRead(pin);
}
