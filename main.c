#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"
#include "uart.h"

int main(void){

  WS2812B_Init();
  UART_Init(9600);
  UART_Tx_Text_NL("Debug Started");
  DDRD |= (1<<4);
  PORTD&=~(1<<4);
  
  uint8_t cmd = 0;
  
  while(1){
    
	if(UART_Data_Available()){
	  PORTD|= (1<<4);
	  cmd = UART_Buf_Get(0);
	  UART_Data_Print_Buf();
	  UART_RX_Packet_Read_Complete();
	  PORTD&=~(1<<4);
	}
	
	
	
	
	if((cmd == 'R') ||(cmd == 'r') ){
	  WS2812B_send_rgb_Target(128,0,0);
	  PORTD|= (1<<4);
	  UART_Tx_Text_NL("Executed RED");
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'I') || (cmd == 'i')){
	  WS2812B_send_rgb_Target(0,128,128);
	  PORTD|= (1<<4);
	  UART_Tx_Text_NL("Executed ICE Blue");
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'O')  || (cmd == 'o')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0,0,0);
	  UART_Tx_Text_NL("Executed Off");
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'G')  || (cmd == 'g')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0,128,0);
	  UART_Tx_Text_NL("Executed Green");
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
		
		
	else if((cmd == 'B')  || (cmd == 'b')){
	  PORTD|= (1<<4);
	  WS2812B_send_rgb_Target(0,0,128);
	  UART_Tx_Text_NL("Executed Blue");
	  cmd = 0;
	  PORTD&=~(1<<4);
	}
	
	
	WS2812B_Sync();
	
	
  }
}