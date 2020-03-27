#include "leds.h"

#define ALL_OFF    0       //constante para apagar los Leds 
#define ALL_ON     0xFFFF  //constante para apagar todos los leds
#define BIT_ON     1       //constante para fijar el primer bit en uno 
#define LED_OFFSET 1       // constante para convertir el numero de led en bit 
static uint16_t *leds;

uint8_t Leds_Bits(uint8_t led){
    return (BIT_ON<<(led-LED_OFFSET));
}

void Leds_Create(uint16_t *direccion){
    leds=direccion;
    *direccion=ALL_OFF;
}

void Leds_On(uint8_t led){
*leds |=Leds_Bits(led);    //Es lo mismo *leds =*leds | (1<<(led-1)); 

}

void Leds_Off(uint8_t led){
    *leds &=~Leds_Bits(led);
}

void Leds_AllOn(void){
    *leds=ALL_ON;

}