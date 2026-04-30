/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    clock.h
  * @brief   CMSIS-only clock configuration for STM32F103
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CLOCK_H
#define CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f103xb.h"

/* Exported functions prototypes ---------------------------------------------*/
void SystemClock_Config(void);

/* TODO: Future clock functions for videos */
// void HSE_Config(void);
// void PLL_72MHz_Config(void);
// void Clock_Output_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* CLOCK_H */
