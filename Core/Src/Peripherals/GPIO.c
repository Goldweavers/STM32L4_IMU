/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
#include "Peripherals/GPIO.h"

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
        * Free pins are configured automatically as Analog
*/
void vGPIOInit (void)
{

  GPIO_InitTypeDef xGPIOInitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (GPIOE, M24SR64_Y_RF_DISABLE_Pin | M24SR64_Y_GPO_Pin
							| ISM43362_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (GPIOA, ARD_D10_Pin | SPBTLE_RF_RST_Pin
							| ARD_D9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (GPIOB,
					 ARD_D8_Pin | ISM43362_BOOT0_Pin | ISM43362_WAKEUP_Pin
					 | LED2_Pin
					 | SPSGRF_915_SDN_Pin | ARD_D5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (GPIOD, USB_OTG_FS_PWR_EN_Pin | PMOD_RESET_Pin
							| STSAFE_A100_RESET_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (SPBTLE_RF_SPI3_CSN_GPIO_Port, SPBTLE_RF_SPI3_CSN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (GPIOC, VL53L0X_XSHUT_Pin
							| LED3_WIFI__LED4_BLE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (SPSGRF_915_SPI3_CSN_GPIO_Port, SPSGRF_915_SPI3_CSN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin (ISM43362_SPI3_CSN_GPIO_Port, ISM43362_SPI3_CSN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin */
  xGPIOInitStruct.Pin =
	  M24SR64_Y_RF_DISABLE_Pin | M24SR64_Y_GPO_Pin | ISM43362_RST_Pin
	  | ISM43362_SPI3_CSN_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  xGPIOInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init (GPIOE, &xGPIOInitStruct);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin */
  xGPIOInitStruct.Pin = USB_OTG_FS_OVRCR_EXTI3_Pin | SPSGRF_915_GPIO3_EXTI5_Pin
						| SPBTLE_RF_IRQ_EXTI6_Pin | ISM43362_DRDY_EXTI1_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_IT_RISING;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOE, &xGPIOInitStruct);

  /*Configure GPIO pin : PtPin */
  xGPIOInitStruct.Pin = BUTTON_EXTI13_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_IT_FALLING;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (BUTTON_EXTI13_GPIO_Port, &xGPIOInitStruct);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3 
                           PC4 PC5 PC10 PC11 
                           PC12 */
  xGPIOInitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3
						| GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_10 | GPIO_PIN_11
						| GPIO_PIN_12;
  xGPIOInitStruct.Mode = GPIO_MODE_ANALOG;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOC, &xGPIOInitStruct);

  /*Configure GPIO pins : PA0 PA1 PA3 PA4 
                           PA5 PA6 PA7 PA9 
                           PA10 PA11 PA12 */
  xGPIOInitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_3 | GPIO_PIN_4
						| GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_9
						| GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12;
  xGPIOInitStruct.Mode = GPIO_MODE_ANALOG;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOA, &xGPIOInitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  xGPIOInitStruct.Pin = ARD_D10_Pin | SPBTLE_RF_RST_Pin | ARD_D9_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  xGPIOInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init (GPIOA, &xGPIOInitStruct);

  /*Configure GPIO pin : PtPin */
  xGPIOInitStruct.Pin = ARD_D3_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_IT_RISING;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (ARD_D3_GPIO_Port, &xGPIOInitStruct);

  /*Configure GPIO pins : PB1 PB10 PB11 PB3 
                           PB8 PB9 */
  xGPIOInitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_3
						| GPIO_PIN_8 | GPIO_PIN_9;
  xGPIOInitStruct.Mode = GPIO_MODE_ANALOG;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOB, &xGPIOInitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin PBPin */
  xGPIOInitStruct.Pin =
	  ARD_D8_Pin | ISM43362_BOOT0_Pin | ISM43362_WAKEUP_Pin | LED2_Pin
	  | SPSGRF_915_SDN_Pin | ARD_D5_Pin | SPSGRF_915_SPI3_CSN_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  xGPIOInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init (GPIOB, &xGPIOInitStruct);

  /*Configure GPIO pins : PE7 PE9 PE10 PE11 
                           PE12 PE13 PE14 PE15 */
  xGPIOInitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11
						| GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  xGPIOInitStruct.Mode = GPIO_MODE_ANALOG;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOE, &xGPIOInitStruct);

  /*Configure GPIO pins : PD8 PD9 PD1 PD3 
                           PD4 PD5 PD6 */
  xGPIOInitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_1 | GPIO_PIN_3
						| GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
  xGPIOInitStruct.Mode = GPIO_MODE_ANALOG;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOD, &xGPIOInitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin 
                           PDPin */
  xGPIOInitStruct.Pin =
	  LPS22HB_INT_DRDY_EXTI0_Pin | LSM6DSL_INT1_EXTI11_Pin | ARD_D2_Pin
	  | HTS221_DRDY_EXTI15_Pin
	  | PMOD_IRQ_EXTI12_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_IT_RISING;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOD, &xGPIOInitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin */
  xGPIOInitStruct.Pin =
	  USB_OTG_FS_PWR_EN_Pin | SPBTLE_RF_SPI3_CSN_Pin | PMOD_RESET_Pin
	  | STSAFE_A100_RESET_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  xGPIOInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init (GPIOD, &xGPIOInitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  xGPIOInitStruct.Pin = VL53L0X_XSHUT_Pin | LED3_WIFI__LED4_BLE_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  xGPIOInitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init (GPIOC, &xGPIOInitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  xGPIOInitStruct.Pin = VL53L0X_GPIO1_EXTI7_Pin | LSM3MDL_DRDY_EXTI8_Pin;
  xGPIOInitStruct.Mode = GPIO_MODE_IT_RISING;
  xGPIOInitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init (GPIOC, &xGPIOInitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority (EXTI9_5_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ (EXTI9_5_IRQn);

  HAL_NVIC_SetPriority (EXTI15_10_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ (EXTI15_10_IRQn);

}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
