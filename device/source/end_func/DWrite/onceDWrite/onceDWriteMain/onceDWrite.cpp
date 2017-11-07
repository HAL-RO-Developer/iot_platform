// onceDWrite
// Created 2017/09/20
// By Hirotaka Nagaoka

#include <DeviceControl.h>
#include "EndFunc.h"

#define VALUE        ( 0 )

SSHT onceDWrite( CONTEXT_DATA *cdata, RESULT_DATA *rdata ){
	SSHT rtn = RESULT_OK;
	if( cdata->port.mode != OUTPUT ){
	Digital::SetMode( cdata->port.pin1, OUTPUT );
  }
  Digital::Write( cdata->port.pin1, cdata->value[VALUE] );
  rdata->value = cdata->value[VALUE];
  rdata->result = rtn;
  return rtn;
}
