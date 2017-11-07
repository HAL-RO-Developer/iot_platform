//Slaveへ送信を行う
#include <DeviceControl.h>
#include"EndFunc.h"
int a = 0;
CONTEXT_DATA context;
RESULT_DATA  result;
SSHT I2CSetup( CONTEXT_DATA*, RESULT_DATA*);
SSHT I2CWrite( SINT, SINT, RESULT_DATA*);
void setup() {
  context.port.pin1 = 4; //SDA
  context.port.pin2 = 5;//SCL
  I2CSetup( &context, &result );
}

void loop() {
  I2CWrite(2, a, &result);
  a++;
  delay(1000);
}




