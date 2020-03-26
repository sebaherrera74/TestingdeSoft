/*• Después de la inicialización todos los LEDs
   deben quedar apagados.
• Se puede prender un LED individual.
• Se puede apagar un LED individual.
• Se pueden prender y apagar múltiples LED’s.
• Se pueden prender todos los LEDs de una vez.
• Se pueden apagar todos los LEDs de una vez.
• Se puede consultar el estado de un LED.
• Revisar limites de los parametros.
• Revisar parámetros fuera de los limites.*/

#include "unity.h"
#include "leds.h"

void setUp(void){
}
void tearDown(void){
}


void test_ledsOffAfterCreate(void){
    uint16_t ledsVirtuales=0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

void test_IndividualLedsOn(void){
    uint16_t ledsVirtuales;
    int led=3;
    Leds_Create(&ledsVirtuales);
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(1<<(led-1),ledsVirtuales);

}