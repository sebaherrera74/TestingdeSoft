#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


static uint16_t ledsVirtuales;



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

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedsOn(void){

    uint8_t led=3;

    Leds_On(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<(led- 1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedsOff(void){

    uint16_t ledsVirtuales;

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

    Leds_AllOff();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

}
