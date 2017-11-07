//Slaveから受信を行う
#include <DeviceControl.h>
#include"EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;  
SSHT I2CSetup( CONTEXT_DATA*,RESULT_DATA*);
SSHT I2CRequestonebyte( SINT,RESULT_DATA*);
SSHT I2CRead(RESULT_DATA*);

void setup() {
  context.port.pin1 = 4; //SDA
  context.port.pin2 = 5;//SCL
 I2CSetup( &context,&result );
  Serial.begin(9600);
}

void loop() {
 I2CRequestonebyte(8,&result );
 I2CRead(&result);
 Serial.println(result.value);
 delay(500);
}
  


