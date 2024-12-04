
/*
Addressable LEDs are highly dependent on precise timings
Please check clock frequency and timings before proceed

Used System:

CPU  : ATmega328P
F_CPU: 12MHz

For other clock frequency, nop operations must be modified
*/

#include <avr/io.h>
#include <util/delay.h>
#include "ws2812b.h"


typedef struct ws2812b_t{
	uint8_t Red;
	uint8_t Green;
	uint8_t Blue;
	uint8_t TargetRed;
	uint8_t TargetGreen;
	uint8_t TargetBlue;
}ws2812b_t;

ws2812b_t WS2812B = {
    .Red = 0,
	.Green = 0,
	.Blue = 0,
	.TargetRed = 0,
	.TargetGreen = 0,
	.TargetBlue = 0
};


void WS2812B_Gpio_Init(void){
  WS2812B_DDR  |=  (1<<WS2812B_bp);
  WS2812B_PORT &=~ (1<<WS2812B_bp);
}

void WS2812B_Send_Byte(uint8_t val){
  if(val & 0x80){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x40){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x20){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x10){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x08){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x04){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x02){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
  
  
  if(val & 0x01){
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
  }else{
	WS2812B_PORT |=  (1<<WS2812B_bp);
    asm( "nop ");
    asm( "nop ");
    asm( "nop ");
    WS2812B_PORT &=~ (1<<WS2812B_bp);
    asm( "nop ");
	asm( "nop ");
    asm( "nop ");
    asm( "nop ");
	asm( "nop ");
  }
}

void WS2812B_Send_Pixel(uint8_t r, uint8_t g, uint8_t b){
  WS2812B_Send_Byte(g);
  WS2812B_Send_Byte(r);
  WS2812B_Send_Byte(b);
}

void WS2812B_Pixel_Delay(void){
  for(uint32_t i=0;i<40000;i++){
	asm( "nop ");
  }
}


void WS2812B_send_rgb(uint8_t red, uint8_t green, uint8_t blue){
	WS2812B_Send_Byte(green);
	WS2812B_Send_Byte(red);
	WS2812B_Send_Byte(blue);
	WS2812B.Red = red;
	WS2812B.Green = green;
	WS2812B.Blue = blue;
}



void WS2812B_send_rgb_Target(uint8_t red, uint8_t green, uint8_t blue){
	if(red > MAX_VALUE){
	  WS2812B.TargetRed = MAX_VALUE;
	}
	else{
		WS2812B.TargetRed = red;
	}
	
	if(green > MAX_VALUE){
	  WS2812B.TargetGreen = MAX_VALUE;
	}
	else{
		WS2812B.TargetGreen = green;
	}
	
	if(blue > MAX_VALUE){
	  WS2812B.TargetBlue = MAX_VALUE;
	}
	else{
		WS2812B.TargetBlue = blue;
	}
}


void WS2812B_Sync(void){
	uint8_t break_condition = 0;
	for(uint8_t i=0; i<255; i++){
		
		if(WS2812B.TargetRed > WS2812B.Red){
			WS2812B.Red++;
		} 
		else if(WS2812B.TargetRed < WS2812B.Red){
			WS2812B.Red--;
		}else{
			break_condition |= 0x01;
		}
		
		if(WS2812B.TargetGreen > WS2812B.Green){
			WS2812B.Green++;
		} 
		else if(WS2812B.TargetGreen < WS2812B.Green){
			WS2812B.Green--;
		} 
		else{
			break_condition |= 0x02;
		}
		
		if(WS2812B.TargetBlue > WS2812B.Blue){
			WS2812B.Blue++;
		} 
		else if(WS2812B.TargetBlue < WS2812B.Blue){
			WS2812B.Blue--;
		}
		else{
			break_condition |= 0x04;
		}
		
		for(uint8_t i=0;i<120;i++){
		  WS2812B_send_rgb(WS2812B.Red, WS2812B.Green, WS2812B.Blue);
		}
		_delay_us(3000);
		
		if(break_condition == 0x07){
			break;
		}
	}
	
}

  
void WS2812B_Init(void){
  WS2812B_Gpio_Init();
}


