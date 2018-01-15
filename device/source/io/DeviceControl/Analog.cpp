#include "arduino.h"
#include "DeviceControl.h"

void Analog::Write(int pin, int value)
{
	analogWrite(pin, value);
}

int Analog::Read(int pin)
{
	return analogRead(pin);
}
