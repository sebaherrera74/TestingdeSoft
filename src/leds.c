#include "leds.h"

static uint16_t *leds;

void Leds_Create(uint16_t *direccion){
    leds=direccion;
    *direccion=0;
}

void Leds_On(uint8_t led){
*leds=0x0004;

}