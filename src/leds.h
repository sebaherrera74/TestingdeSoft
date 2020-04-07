#include <stdint.h>

void Leds_Create(uint16_t *direccion);

void Leds_On(uint16_t led);
void Leds_Off(uint16_t led);
void Leds_AllOn(void);
void Leds_AllOff(void);
uint16_t ConsultaLedOn(uint16_t led);