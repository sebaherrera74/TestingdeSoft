#include "leds.h"

#define ALL_OFF    0x0000      //constante para apagar los Leds 
#define ALL_ON     0xFFFF  //constante para apagar todos los leds
#define BIT_ON     1       //constante para fijar el primer bit en uno 
#define LED_OFFSET 1       // constante para convertir el numero de led en bit 

static uint16_t *leds; //direccion de leds 
static uint16_t ledsImage;

uint8_t Leds_Bits(uint16_t led){
    return (BIT_ON<<(led-LED_OFFSET));
}

void Leds_Create(uint16_t *direccion){
    leds=direccion;
    ledsImage=ALL_OFF; 
    *leds=ledsImage;

}

void Leds_On(uint8_t led){
ledsImage |=Leds_Bits(led);    //Es lo mismo *leds =*leds | (1<<(led-1)); 
*leds=ledsImage;

}

void Leds_Off(uint8_t led){
    ledsImage &=~Leds_Bits(led);
    *leds=ledsImage;
}

void Leds_AllOn(void){
    ledsImage=ALL_ON;
    *leds=ledsImage;

}

void Leds_AllOff(void){
    *leds=ALL_OFF;

}
