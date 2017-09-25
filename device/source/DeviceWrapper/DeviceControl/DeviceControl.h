#ifndef DeviceControl_h
#define DeviceControl_h
#include "arduino.h"
#include <Wire.h>
#include <SoftwareSerial.h>

class Digital
{
	public:
		static void SetMode( int pin, int mode );
		static void Write( int pin, int value );
		static int Read( int pin );
	private:
		Digital( );
};

class Analog
{
	public:
		static void Write( int pin, int value );
		static int Read( int pin );
	private:
		Analog( );
};

class UART
{
	public:
		static int available( );
		static void begin( unsigned long speed );
		static void end( );
		static int Read( );
		static int peek( );
		static void flush( );
		static int Write( int value );
		static int Write( char* string );
		static int Write( unsigned char* buffer, int length );
		static int print( int value );
		static int print( char* string );
		static int print( int value, int format );
		static int println( int value );
		static int println( char* string );
		static int println( int value, int format );
	private:
		UART( );
};

class I2C
{
	public:
		static void begin( int address );
		static int reqFrom( int address, int count );
		static void beginTransmission( int address );
		static int endTransmission( );
		static int Write( int value );
		static int Write( char* string );
		static int Read( );
		static int available( );
	private:
		I2C( );
};

#endif
