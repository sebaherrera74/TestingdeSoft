#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;

static uint16_t ledsImage;



void setUp(void){

    Leds_Create(&ledsVirtuales);

}



void tearDown(void){

}





void test_ledsOffAfterCreate(void){

    uint16_t ledsVirtuales=0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedsOn(void){

    uint8_t led=3;

    Leds_On(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<(led-1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedsOff(void){

    uint8_t led=3;

    Leds_On(led);

    Leds_Off(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX16);

}





void test_MulipleLedOnAndOff(void){

    Leds_On(2);

    Leds_On(5);

    Leds_Off(2);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<(5-1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_HEX16);

}





void test_PrendeTodosLeds(void){

    Leds_AllOn();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_HEX16);

}





void test_ApagaTodosLeds(void){

    Leds_AllOn();

    Leds_AllOff();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);

}







void test_ConsultaEstadoLed(void) {

    ledsVirtuales=0xFFFF;

    Leds_On(8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x80)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

}
