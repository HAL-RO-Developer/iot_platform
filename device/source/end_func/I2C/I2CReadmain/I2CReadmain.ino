//Slaveから受信を行う
#include <DeviceControl.h>
#include"EndFunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;  

  SSHT Value[2] = {0,8};
void setup() {
  context.value = Value;
  context.port.pin1 = 4; //SDA
  context.port.pin2 = 5;//SCL
 I2CSetup( &context,&result );
  Serial.begin(9600);
}

void loop() {
 I2CRequestonebyte( &context,&result );
 I2CRead( &context,&result );
 Serial.println(result.value);
 delay(500);
}

/* Copyright HAL College of Technology & Design */


