#include "arduino.h"
#include "DeviceControl.h"



void I2C::begin(int SDA,int SCL)
{
	Wire.begin( );
}
int I2C::reqFrom(int address, int count)
{
	return Wire.requestFrom(address, count);
}

void I2C::beginTransmission(int address)
{
	Wire.beginTransmission(address);
}

int I2C::endTransmission()
{
	return Wire.endTransmission();
}

int I2C::Write(int value)
{
    return Wire.write(value);
}

int I2C::Write(char* string)
{
    return Wire.write(string);
}

int I2C::Read()
{
	return Wire.read();
}

int I2C::available()
{
    return Wire.available();
}
