//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
//
// Standalone STM32F4 led blink sample (trace via DEBUG).
//
// In debug configurations, demonstrate how to print a greeting message
// on the trace device. In release configurations the message is
// simply discarded.
//
// Then demonstrates how to blink a led with 1 Hz, using a
// continuous loop and SysTick delays.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//



// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#include "Conc.h"
#include "Types.h"
#include "util.h"
#include "GPIO_interface.h"




#define SWITCH1         GPIO_u8PIN0
#define LED_RED         GPIO_u8PIN63
#define LED_BLUE        GPIO_u8PIN62
#define LED_YELLOW      GPIO_u8PIN61
#define LED_ORANGE      GPIO_u8PIN60
//#define PORTF           5

#define RELEASED        0
#define PRESSED         1
#define BOUNCING        2

#define MAXCOUNT        10

//#define GETPIN(REG,BIN)     ((REG>>BIN)&0x01)



void read_Sw(u8 ,u16 *);

void main()
{
//	u16 val=0;
//	GPIO_voidInit(GPIO_u8PORTD,GPIO_CLK_ENABLE);
//	GPIO_u8WritePort(GPIO_u8PORTB,1);
//
//	while(1){
		//GPIO_u8ReadOutputData(GPIO_u8PORTB,&val);
  u16 SW_Val = RELEASED;
  u16 val=0;
  GPIO_voidInit(GPIO_u8PORTD,GPIO_CLK_ENABLE);
  GPIO_voidInit(GPIO_u8PORTA,GPIO_CLK_ENABLE);
  GPIO_u8SetPinPUPD(GPIO_u8PIN0,GPIO_PuPd_DOWN);
//  CLKGPIO |= 1<<PORTF;      //enable clk to port_F
//  DIRECTION_F = (1<<LED_RED);  // Sw i/p & Led o/p
//  ENABLE_F = (1<<LED_RED)|(1<<SWITCH1);
//  DATA_F=0;
//  PULLUP_F = (1<<SWITCH1);
  GPIO_u8WriteBit(LED_BLUE,GPIO_u8HIGH);
  GPIO_u8WriteBit(LED_ORANGE,GPIO_u8HIGH);
  GPIO_u8WriteBit(LED_YELLOW,GPIO_u8HIGH);
  GPIO_u8SetPinMode(GPIO_u8PIN0,GPIO_Mode_IN);
  while(1)
  {
    read_Sw(SWITCH1,&SW_Val);
    if (SW_Val == PRESSED)
    {

    	GPIO_ReadOutputDataBit(LED_RED,&val);
    	GPIO_u8WriteBit(LED_YELLOW,val);
    	val = val ^ 0x01;
    	GPIO_u8WriteBit(LED_RED,val);

//      val=DATA_F & (1<<LED_RED);
//      val = val ^ (1<<LED_RED);
//      DATA_F = val;
      while(SW_Val == PRESSED)
      {read_Sw(SWITCH1,&SW_Val);}

    }
    else{

    }
  }

  return ;
}



void read_Sw(u8 Copy_SwitchPin,u16 *Copy_u8PtrToVal)
{
  static int TACTILE_u8State =           RELEASED;
  static int TACTILE_u8CounterUp = 	  0;
  static int TACTILE_u8CounterDown =     0;
  static int TACTILE_u8TactileVal = 	  RELEASED;
  u16 Local_u8TactileVal=RELEASED;


    GPIO_u8ReadInputDataBit(Copy_SwitchPin,&Local_u8TactileVal);

    switch(TACTILE_u8State)
    {
	case RELEASED:
          if(Local_u8TactileVal == PRESSED)
            {
		TACTILE_u8State = BOUNCING;
		TACTILE_u8CounterDown = 0;
            }
	else if (Local_u8TactileVal == RELEASED)
            {
		TACTILE_u8TactileVal = RELEASED;
        }
        else{
        }
	*Copy_u8PtrToVal = TACTILE_u8TactileVal;
	break;
	case BOUNCING:
            if(Local_u8TactileVal == PRESSED)
            {
                TACTILE_u8CounterUp++;
                TACTILE_u8CounterDown = 0;
            }
            else if (Local_u8TactileVal == RELEASED)
            {
                TACTILE_u8CounterDown++;
		TACTILE_u8CounterUp = 0;
            }
            else{
            }
            if(TACTILE_u8CounterUp >= MAXCOUNT)
            {
		TACTILE_u8State = PRESSED;
            }
            else{
            }
            if(TACTILE_u8CounterDown >= MAXCOUNT)
            {
		TACTILE_u8State = RELEASED;
            }
            else{
            }
            break;
	case PRESSED:
          if (Local_u8TactileVal == RELEASED)
            {
		TACTILE_u8CounterUp = 0;
		TACTILE_u8State = BOUNCING;
            }
            else if (Local_u8TactileVal == PRESSED)
            {
                TACTILE_u8TactileVal = PRESSED;
            }
            else{
            }
		*Copy_u8PtrToVal=TACTILE_u8TactileVal;
		break;
            default:
		break;
      }

}
//void main(void)
//{
//	u16 x=0,y;
//	//GPIO_u8AssignPortClk(GPIO_u8PORTD,GPIO_CLK_ENABLE);
//	GPIO_voidInit(GPIO_u8PORTD,GPIO_CLK_ENABLE);
//
//  // Infinite loop
//  while (1)
//    {
////	  GPIO_u8SetPortMode(GPIO_u8PORTD,10);
////	  GPIO_u8SetPortMode(GPIO_u8PORTD,11);
////	  GPIO_u8SetPortMode(GPIO_u8PORTD,00);
////	  GPIO_u8SetPortType(GPIO_u8PORTD,0);
////	  GPIO_u8SetPortType(GPIO_u8PORTD,1);
////	  //GPIO_u8SetPortType(GPIO_u8PORTD,11);
////	  GPIO_u8SetPortPUPD(GPIO_u8PORTD,10);
////	  GPIO_u8SetPortPUPD(GPIO_u8PORTD,11);
////	  GPIO_u8SetPortPUPD(GPIO_u8PORTD,00);
//	  //GPIO_u8WriteBit(GPIO_u8PIN63,1);
//	 // GPIO_u8WriteBit(GPIO_u8PIN63,0);
////	  GPIO_u8SetOrResetPinBSSR(GPIO_u8PIN63,1);
////	  GPIO_u8SetOrResetPinBSSR(GPIO_u8PIN62,1);
////	  GPIO_u8SetOrResetPinBSSR(GPIO_u8PIN63,0);
//	  //GPIO_u8WriteBit(GPIO_u8PIN63,GPIO_u8LOW);
//	 // GPIO_u8WritePort(GPIO_u8PORTD,GPIO_u8LOW);
//	  //GPIO_u8WriteBit(GPIO_u8PIN60,GPIO_u8HIGH);
//	  //GPIO_ReadOutputDataBit(GPIO_u8PIN60,&y);
//	  //GPIO_u8ReadOutputData(GPIO_u8PORTD,&x);
//	  //GPIO_u8SetBitSpeed(GPIO_u8PIN48,GPIO_Speed_Medium);
//	  //GPIO_u8LCKRPin(GPIO_u8PIN48);
//	  //GPIO_u8SetPinMode(GPIO_u8PIN48,GPIO_Mode_AN);
//	  //GPIO_u8SetPinMode(GPIO_u8PIN48,GPIO_Mode_IN);
////	  GPIO_u8SetPinType(63,GPIO_OType_PP);
////	  GPIO_u8SetPinType(63,GPIO_OType_OD);
//	  //GPIO_u8SetPinType(GPIO_u8PIN63,GPIO_Speed_Medium);
//	  //GPIO_u8SetPinType(GPIO_u8PIN63,GPIO_Speed_Low);
////	  GPIO_u8AlternatePin(GPIO_u8PIN63,GPIO_AFR_TIM3_To_TIM5);
////	  GPIO_u8AlternatePin(GPIO_u8PIN63,GPIO_AFR_ETH);
////	  GPIO_u8AlternatePin(GPIO_u8PIN63,GPIO_AFR_EVENTOUT);
////	  GPIO_u8AlternatePin(GPIO_u8PIN63,GPIO_AFR_Sys);
////
////	  GPIO_u8AlternatePin(GPIO_u8PIN48,GPIO_AFR_TIM3_To_TIM5);
////	  GPIO_u8AlternatePin(GPIO_u8PIN48,GPIO_AFR_ETH);
////	  GPIO_u8AlternatePin(GPIO_u8PIN48,GPIO_AFR_EVENTOUT);
////	  GPIO_u8AlternatePin(GPIO_u8PIN48,GPIO_AFR_Sys);
////	  GPIO_u8SetPinPUPD(63,GPIO_PuPd_NOPULL);
////	  GPIO_u8SetPinPUPD(63,GPIO_PuPd_UP);
////	  GPIO_u8SetPinPUPD(GPIO_u8PIN63,GPIO_PuPd_DOWN);
//	  //GPIO_u8SetPinPUPD(GPIO_u8PIN63,GPIO_Speed_Low);
//
//	  //GPIO_u8WriteBit(140,GPIO_u8HIGH);
//	  //GPIO_u8WritePort(GPIO_u8PORTD,GPIO_u8HIGH);
//	  //GPIO_u8WriteBit(GPIO_u8PIN60,GPIO_u8LOW);
//	  //GPIO_ReadOutputDataBit(GPIO_u8PIN60,&y);
//	  //GPIO_u8ReadOutputData(GPIO_u8PORTD,&x);
//	  //GPIO_u8AssignPortClk(GPIO_u8PORTD,GPIO_CLK_DISABLE);
//	  //GPIO_u8WritePort(GPIO_u8PORTD,0x0000);
//    }
//  // Infinite loop, never return.
//}



// ----------------------------------------------------------------------------
