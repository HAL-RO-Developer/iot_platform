/*
    StatusLED.h

    ステータスLED管理クラス

    Created 2017/11/15
    By Shogo Tanaka
*/
#include "StatusLED.h"

StatusLED::StatusLED(int pin)
{
	this->pin = pin;
	pinMode( this->pin, OUTPUT );
}

StatusLED::~StatusLED()
{}

void StatusLED::setValue( int value )
{
  this->value = value;
}

SINT StatusLED::getValue()
{
  return value;
}

void StatusLED::write()
{
	digitalWrite( pin, value );
}

void StatusLED::write(int value)
{
	digitalWrite( pin, value );
}

void StatusLED::startBlink(int ms)
{
	ticker.attach_ms<StatusLED*>( ms, flash, this );
}

void StatusLED::stopBlink()
{
	ticker.detach();
}

void flash(StatusLED* led)
{
	led->setValue(!(led->getValue()));
}

