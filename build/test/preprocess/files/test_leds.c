#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


void setUp(void){

}

void tearDown(void){

}







void test_ledsOffAfterCreate(void){

    uint16_t ledsVirtuales=0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_HEX16);

}





void test_IndividualLedsOn(void){

    uint16_t ledsVirtuales;

    uint8_t led=3;

    Leds_Create(&ledsVirtuales);

    Leds_On(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1<<(led-1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}



void test_IndividualLedsOff(void){

    uint16_t ledsVirtuales;

    uint8_t led=3;

    Leds_Create(&ledsVirtuales);

    Leds_On(led);

    Leds_Off(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX16);

}
