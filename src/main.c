#include "stm32f0xx_conf.h"
#include "stm32f072b_discovery.h"

RCC_ClocksTypeDef RCC_Clocks;
__IO uint32_t TimingDelay = 0;
__IO uint32_t UserButtonPressed = 0x00;
uint8_t currentState = 1;

void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

void EXTI0_IRQHandler(void)
{
  if (EXTI_GetITStatus(USER_BUTTON_EXTI_LINE) != RESET)
  {
    /* Set the UserButtonPressed variable */
    UserButtonPressed = 0x01;

    /* Clear the EXTI line pending bit */
    EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
  }
}


int main(void)
{
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);


    // high level access to GPIO (via the board library)
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_LEDInit(LED6);


    currentState = 0;
    while(1)
    {switch (currentState)
        {
         case 0:
            STM_EVAL_LEDOn(LED4);
            STM_EVAL_LEDOn(LED6);
            Delay(100);
            STM_EVAL_LEDOff(LED4);
            STM_EVAL_LEDOff(LED6);
            Delay(25);
            break;
         case 1:
            STM_EVAL_LEDOn(LED3);
            STM_EVAL_LEDOn(LED5);
            Delay(100);
            STM_EVAL_LEDOff(LED3);
            STM_EVAL_LEDOff(LED5);
            Delay(25);
            break;
         case 2:
            STM_EVAL_LEDOn(LED3);
            STM_EVAL_LEDOn(LED4);
            Delay(100);
            STM_EVAL_LEDOff(LED3);
            STM_EVAL_LEDOff(LED4);
            Delay(25);
            break;
         case 3:
            STM_EVAL_LEDOn(LED5);
            STM_EVAL_LEDOn(LED6);
            Delay(100);
            STM_EVAL_LEDOff(LED5);
            STM_EVAL_LEDOff(LED6);
            Delay(25);
            break;
         case 4:
            STM_EVAL_LEDOn(LED3);
            Delay(25);
            STM_EVAL_LEDOff(LED3);
            Delay(25);
            break;
         case 5:
            STM_EVAL_LEDOn(LED4);
            Delay(25);
            STM_EVAL_LEDOff(LED4);
            Delay(25);
            break; 
         case 6:
            STM_EVAL_LEDOn(LED5);
            Delay(25);
            STM_EVAL_LEDOff(LED5);
            Delay(25);
            break;  
         case 7:
            STM_EVAL_LEDOn(LED6);
            Delay(25);
            STM_EVAL_LEDOff(LED6);
            Delay(25);
            break;             

        }

      /* Change the state */
    if (currentState<4)
      {currentState = (currentState + 1) % 8;  // 8 states 
      Delay(100);
      }
    else
      {currentState = (currentState + 1) % 8;  // 8 states 
      Delay(50);  
      }  
    }
}

