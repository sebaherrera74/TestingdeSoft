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

   ), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_HEX16);

}
