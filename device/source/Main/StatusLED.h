/*
    StatusLED.h

    ステータスLED管理クラス

    Created 2017/11/15
    By Shogo Tanaka
*/
#ifndef __STATUS_LED_CONTROL_H__
#define __STATUS_LED_CONTROL_H__

#include "ArduinoLibrary.h"
#include "System.h"
#include "constants.h"

class StatusLED{
	private:
		SINT pin;
		SINT value = HIGH;		
		Ticker ticker;
	public:
		StatusLED(int pin);
		~StatusLED();
    void setValue( int value );
    SINT getValue();
		void write();
		void write(int value);
		void startBlink(int ms);
		void stopBlink();
};

void flash(StatusLED* led);

#endif /* __STATUS_LED_CONTROL_H__ */
