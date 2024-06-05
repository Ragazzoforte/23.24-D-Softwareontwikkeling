//--------------------------------------------------------------
// File     : main.h
//--------------------------------------------------------------
/* USER CODE BEGIN Header */
/**
 * @file main.h
 * @author Michel Vollmuller (michel.vollmuller@gmail.com)
 * @author Tim Wannet (tim.wannet@student.hu.nl)
 * @author Tijmen Willems (tijmen.willems@student.hu.nl)
 * @brief headerfile of main.c
 * @version 0.1
 * @date 05-06-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif
#endif

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

//--------------------------------------------------------------
#ifndef __STM32F4_UB_MAIN_H
#define __STM32F4_UB_MAIN_H

#define BAUD_RATE 115200

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32f4xx.h"
#include "vga_driver.h"
#include "stm32_ub_vga_screen.h"
#include "logic_layer.h"
#include "fonts.h"
#include "bitmap.h"
#include "user_interface.h"
#include "stm32_ub_vga_screen.h"
#include "uart.h"
#include "stm32f4xx_it.h"
#include "user_interface.h"

// #include <stdio.h>
#include <string.h>
// #include <stdint.h>
#include <stdlib.h>
#include <math.h>
//--------------------------------------------------------------
#endif // __STM32F4_UB_MAIN_H
