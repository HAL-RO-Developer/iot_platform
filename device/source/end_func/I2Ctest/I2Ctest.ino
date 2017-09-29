//Slaveから受信を行う
#include <DeviceControl.h>
#include"EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;  
SSHT I2CSetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata);
SSHT I2CRequestonebyte( SINT SlaveID,RESULT_DATA *rdata);
SSHT I2CRead(RESULT_DATA *rdata);

void setup() {
  context.port[0] = 4; //SDA
  context.port[1] = 5;//SCL
 I2CSetup( &context,&result );
  Serial.begin(9600);
}

void loop() {
 I2CRequestonebyte(8,&result );
 I2CRead(&result);
 Serial.println(result.value);
 delay(500);
}
  



