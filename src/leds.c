#include "leds.h"

#define ALL_OFF    0x0000     //constante para apagar los Leds 
#define ALL_ON     0xFFFF     //constante para apagar todos los leds
#define BIT_ON     1          //constante para fijar el primer bit en uno 
#define LED_OFFSET 1          //  constante para convertir el numero de led en bit 

static uint16_t *leds; //direccion de leds 
static uint16_t ledsImage;

static void ActualizoHardware(void){
    *leds=ledsImage;
}

uint16_t Leds_Bits(uint16_t led){
    return BIT_ON<<(led-LED_OFFSET);
}

void Leds_Create(uint16_t *direccion){
    leds=direccion;
    ledsImage=ALL_OFF; 
    ActualizoHardware();

}

void Leds_On(uint16_t led){
     ledsImage |=Leds_Bits(led);    //Es lo mismo *leds =*leds | (1<<(led-1)); 
     ActualizoHardware();

}

void Leds_Off(uint16_t led){
    ledsImage &=~Leds_Bits(led);
    ActualizoHardware();
}

void Leds_AllOn(void){
    ledsImage=ALL_ON;
    ActualizoHardware();

}

void Leds_AllOff(void){
    ledsImage=ALL_OFF;
    ActualizoHardware();

}

uint16_t ConsultaLedOn(uint16_t led){
    uint16_t posicion=led-LED_OFFSET;
    uint16_t mascara=ledsImage & BIT_ON<<(led-LED_OFFSET);
    return mascara>>posicion;
    ActualizoHardware();
}

uint16_t ConsultaLedOff(uint16_t led){
    ledsImage=ALL_ON;
    uint16_t posicion=led-LED_OFFSET;
    uint16_t mascara=ledsImage & BIT_ON<<(led-LED_OFFSET);
    return ~(mascara>>posicion);
    ActualizoHardware();

}