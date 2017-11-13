//Slaveへ送信を行う
#include <DeviceControl.h>
#include"EndFunc.h"
SINT a = 0;
CONTEXT_DATA context;
RESULT_DATA  result;

 SSHT value[2] = {0,8};
void setup() {
 
  context.port.pin1 = 4; //SDA
  context.port.pin2 = 5;//SCL
  context.value = value;
  I2CSetup( &context, &result );
}

void loop() {
  I2CWrite( &context, &result );
  value[0]++;
context.value = value;
  delay(1000);
}




