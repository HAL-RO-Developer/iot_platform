#include <DeviceControl.h>
#include"endfunc.h"

CONTEXT_DATA context;
RESULT_DATA  result;  

SSHT I2Csetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata);
void setup() {
  Serial.begin(9600);
}

void loop() {
  SSHT rtn;
  context.port[0] = 4; //SDA
  context.port[1] = 5;//SCL
  rtn = I2Csetup( &context,&result );
  if(rtn == RESULT_OK){
     Serial.println("I2C setup OK");
    }
}

SSHT I2Csetup( CONTEXT_DATA *cdata,RESULT_DATA *rdata){
    SSHT rtn = RESULT_OK;
    I2C::begin(cdata->port[0],cdata->port[1]);
     rdata->result = rtn;
     return rtn;
  }


