#include <avr/io.h>
#include <util/delay.h>
#include "datahandler.h"
#include "ws2812b.h"
#include "uart.h"




int main(void){

  WS2812B_Init();
  UART_Init(9600);
  UART_Tx_Text_NL("Debug Started");
  DDRD |= (1<<4);
  PORTD&=~(1<<4);
  
  
  uint8_t  cmd = 0;
  uint16_t intensity = 0;
  
  while(1){
    
	if(UART_Data_Available()){
	  PORTD|= (1<<4);
	  for(uint8_t i=0;i<6;i++){
	    DataHandler_Buf_Assign(UART_Buf_Get(i), i) ;
	  }
	  UART_Data_Print_Buf();
	  UART_RX_Packet_Read_Complete();
	  if(DataHandler_Buf_Get(1) == ':'){
	    cmd = DataHandler_Buf_Get(0);
		intensity = DataHandler_Char_To_Dec(2);
		intensity*= 10;
		intensity+= DataHandler_Char_To_Dec(3);
		intensity*= 10;
		intensity+= DataHandler_Char_To_Dec(4);
		if(intensity > 255){
		  intensity = 0;
		  cmd = 0;
		}
		else{
		  WS2812B_Set_Max_Intensity(intensity);
		}
	  }
	  else{
	    intensity = 0;
		cmd = 0;
	  }
	  
	  DataHandler_Buf_Flush();
	  
	  PORTD&=~(1<<4);
	}
	
	
	
	
	if((cmd == 'R') ||(cmd == 'r') ){
	  WS2812B_send_rgb_Target(128,0,0);
	  PORTD|= (1<<4);
	  UART_Tx_Parameter_NL("Executed RED", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'I') || (cmd == 'i')){
	  WS2812B_send_rgb_Target(0,128,128);
	  PORTD|= (1<<4);
	  UART_Tx_Parameter_NL("Executed ICE Blue", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'O')  || (cmd == 'o')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0,0,0);
	  UART_Tx_Parameter_NL("Executed Off", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'G')  || (cmd == 'g')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0,128,0);
	  UART_Tx_Parameter_NL("Executed Green", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'B')  || (cmd == 'b')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0,0,128);
	  UART_Tx_Parameter_NL("Executed Blue", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
	
	else if((cmd == 'P')  || (cmd == 'p')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0x64,0x3B,0x9F);
	  UART_Tx_Parameter_NL("Executed Purple", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
	
	else{
	  UART_Tx_Parameter_NL("Wrong CMD", WS2812B_Get_Max_Intensity());
	  DataHandler_Buf_Flush();
	  cmd = 0;
	}
	
	WS2812B_Sync();
	
	
  }
}