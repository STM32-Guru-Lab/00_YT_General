/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    clock.c
  * @brief   CMSIS-only clock configuration for STM32F103
  *
  *         This module provides low-level clock configuration using
  *         direct CMSIS register access (no HAL).
  *
  *         Current: HSI 8 MHz, no PLL
  *         TODO:    HSE, PLL 72 MHz
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "clock.h"

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* ---------------------------------------------------------------------------*/
/*         Clock Configuration                                                 */
/* ---------------------------------------------------------------------------*/

/**
  * @brief  System Clock Configuration
  *         Configures HSI 8 MHz as system clock with no PLL.
  *         AHB = SYSCLK / 1, APB1 = AHB / 1, APB2 = AHB / 1
  * @note   CMSIS-only: uses direct register access via CMSIS defines.
  *         No HAL functions are used.
  * @retval None
  */
void SystemClock_Config(void)
{
  /* USER CODE BEGIN SystemClock_Config 0 */

  /* USER CODE END SystemClock_Config 0 */

  /* --- HSI activation --- */
  /* Enable HSI oscillator */
  RCC->CR |= RCC_CR_HSION;

  /* Wait until HSI is ready */
  while (!(RCC->CR & RCC_CR_HSIRDY))
    ;

  /* --- Flash latency --- */
  /* 0 wait states for 8 MHz (STM32F103: 0WS up to 24 MHz @ 3.3V) */
  FLASH->ACR = FLASH_ACR_LATENCY_0;

  /* --- System clock source --- */
  /* Select HSI as system clock */
  RCC->CFGR &= ~RCC_CFGR_SW;
  RCC->CFGR |= RCC_CFGR_SW_HSI;

  /* Wait until HSI is active as system clock */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI)
    ;

  /* --- Bus prescalers --- */
  /* AHB = SYSCLK / 1  (HPRE[3:0] = 0b0000) */
  /* APB1 = AHB / 1    (PPRE1[2:0] = 0b000) */
  /* APB2 = AHB / 1    (PPRE2[2:0] = 0b000) */
  RCC->CFGR &= ~(RCC_CFGR_HPRE | RCC_CFGR_PPRE1 | RCC_CFGR_PPRE2);
  RCC->CFGR |= (RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV1 | RCC_CFGR_PPRE2_DIV1);

  /* --- Update CMSIS variable --- */
  /* Reads RCC registers and updates SystemCoreClock */
  SystemCoreClockUpdate();

  /* USER CODE BEGIN SystemClock_Config 1 */

  /* USER CODE END SystemClock_Config 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
