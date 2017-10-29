//Slaveへ送信を行う
#include <DeviceControl.h>
#include"EndFunc.h"
char a='a';
CONTEXT_DATA context;
RESULT_DATA  result;  
SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata);
SSHT I2CWrite( SINT SleaveID, SINT data, RESULT_DATA *rdata);
void setup() {
  context.port.pin1 = 4; //SDA
  context.port.pin2 = 5;//SCL
  I2CSetup( &context,&result );
  Serial.begin(9600);
}

void loop() {
    I2CWrite(2,a,&result);
}




