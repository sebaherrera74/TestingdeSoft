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

static uint16_t ledsVirtuales;
static uint16_t ledsImage;

void setUp(void){
    Leds_Create(&ledsVirtuales);
}

void tearDown(void){
}

//1 Test-Después de la inicialización todos los LEDs deben quedar apagados 
void test_ledsOffAfterCreate(void){
    uint16_t ledsVirtuales=0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//2 Test-Se puede prender un LED individual.
void test_IndividualLedsOn(void){
    uint16_t led=9;
    Leds_On(led);
    TEST_ASSERT_EQUAL_HEX16(1<<(led-1),ledsVirtuales);
}

//3 Test-Se puede apagar un LED individual.
void test_IndividualLedsOff(void){
    uint16_t led=3;
    Leds_On(led);
    Leds_Off(led);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//4 Test-  Se pueden prender y apagar múltiples LED’s.
void test_MulipleLedOnAndOff(void){
    Leds_On(2);
    Leds_On(5);
    Leds_Off(2);
    TEST_ASSERT_EQUAL_HEX16(1<<(5-1),ledsVirtuales);
}

//5 Test -Se pueden prender todos los leds de una vez 
void test_PrendeTodosLeds(void){
    Leds_AllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,ledsVirtuales);
}

//6 Test -Se pueden apagar todos los leds de una vez 
void test_ApagaTodosLeds(void){
    Leds_AllOn();
    Leds_AllOff();
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}


// 7 Test-Consulta estado de un Led  
void test_ConsultaEstadoLed(void) {
   // ledsVirtuales=0xFFFF;
    Leds_On(8);
    TEST_ASSERT_EQUAL_HEX16(0x0080,ledsVirtuales);
}
    
//8 Revisar limites de los parametros 
void test_ledsOnLimites(void){
    Leds_On(1);
    Leds_On(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001,ledsVirtuales);
}
