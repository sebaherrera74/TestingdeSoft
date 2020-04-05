/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_ledsOffAfterCreate(void);
extern void test_IndividualLedsOn(void);
extern void test_IndividualLedsOff(void);
extern void test_MulipleLedOnAndOff(void);
extern void test_PrendeTodosLeds(void);
extern void test_ApagaTodosLeds(void);
extern void test_ConsultaEstadoLed(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}
/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {

            setUp();
            func();

    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_ledsOffAfterCreate, "test_ledsOffAfterCreate", 26);
  run_test(test_IndividualLedsOn, "test_IndividualLedsOn", 33);
  run_test(test_IndividualLedsOff, "test_IndividualLedsOff", 40);
  run_test(test_MulipleLedOnAndOff, "test_MulipleLedOnAndOff", 48);
  run_test(test_PrendeTodosLeds, "test_PrendeTodosLeds", 56);
  run_test(test_ApagaTodosLeds, "test_ApagaTodosLeds", 62);
  run_test(test_ConsultaEstadoLed, "test_ConsultaEstadoLed", 70);

  return UnityEnd();
}
