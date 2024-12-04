

#define  WS2812B_DDR          DDRD
#define  WS2812B_PORT         PORTD
#define  WS2812B_bp           5U

#define  MAX_VALUE            128

void     WS2812B_Gpio_Init(void);
void     WS2812B_Send_Byte(uint8_t val);
void     WS2812B_Send_Pixel(uint8_t r, uint8_t g, uint8_t b);
void     WS2812B_Pixel_Delay(void);
void     WS2812B_send_rgb(uint8_t red, uint8_t green, uint8_t blue);
void     WS2812B_send_rgb_Target(uint8_t red, uint8_t green, uint8_t blue);
void     WS2812B_Sync(void);

void     WS2812B_Init(void);
