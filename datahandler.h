

#ifndef  _DATAHANDLER_H_
#define  _DATAHANDLER_H_





void     DataHandler_Buf_Flush(void);
void     DataHandler_Buf_Assign(uint8_t val, uint8_t index);
uint8_t  DataHandler_Buf_Get(uint8_t index);
uint8_t  DataHandler_Char_To_Dec(uint8_t val);



void     DataHandler_Init(void);






#endif



