

#include <avr/io.h>
#include <util/delay.h>
#include "datahandler.h"


#define  DATA_HANDLER_BUF_SIZE 10

typedef struct datahandler_t{
	uint8_t RawBuf[DATA_HANDLER_BUF_SIZE];
	uint8_t CMD;
}datahandler_t;

datahandler_t DataHandler;


void DataHandler_Buf_Flush(void){
  for(uint8_t i=0;i<DATA_HANDLER_BUF_SIZE;i++){
	DataHandler.RawBuf[i] = 0;
  }
  DataHandler.CMD = 0;
}

void DataHandler_Buf_Assign(uint8_t val, uint8_t index){
  if(index<DATA_HANDLER_BUF_SIZE){
    DataHandler.RawBuf[index] = val;
  }
}

uint8_t DataHandler_Buf_Get(uint8_t index){
  if(index<DATA_HANDLER_BUF_SIZE){
    return DataHandler.RawBuf[index];
  }
  else{
    return 0;
  }
}


uint8_t DataHandler_Char_To_Dec(uint8_t val){
  uint8_t temp = 0;
  if( (val >= 48) && (val >= 57) ){
    temp = (val - 48);
  }
  return temp;
}



void DataHandler_Init(void){
  DataHandler_Buf_Flush();
}

