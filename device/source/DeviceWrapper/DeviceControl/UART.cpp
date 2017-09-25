#include "arduino.h"
#include "DeviceControl.h"

int UART::available( )
{
	return Serial.available( );
}

void UART::begin( unsigned long speed )
{
	Serial.begin( speed );
}

void UART::end( )
{
	Serial.end( );
}

int UART::Read( )
{
	return Serial.read( );
}

int UART::peek( )
{
    return Serial.peek( );
}

void UART::flush( )
{
    Serial.flush( );
}

int UART::Write( int value )
{
	return Serial.write( value );
}

int UART::Write( char* string )
{
	return Serial.write( string );
}

int UART::Write( unsigned char* buffer, int length )
{
	return Serial.write( buffer, length );
}

int UART::print( int value )
{
    return Serial.print( value );
}

int UART::print( int value, int format )
{
    return Serial.print( value, format );
}

int UART::println( int value )
{
    return Serial.println( value );
}

int UART::println( int value, int format )
{
    return Serial.println( value, format );
}
