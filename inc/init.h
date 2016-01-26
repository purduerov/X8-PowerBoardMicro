/* The .h file that will store the function declarations of initialization functions */
#ifndef __INIT_H
#define __INIT_H

#include "main.h"

extern uint16_t thruster[8];

extern TIM_HandleTypeDef htim3;  //timer structure used in pwm
extern TIM_OC_InitTypeDef sConfigOC;  //pwm settings structure

extern CAN_HandleTypeDef hcan2;
extern CanTxMsgTypeDef        TxMessage;
extern CanRxMsgTypeDef        RxMessage;

extern DMA_HandleTypeDef hdma_i2c2_rx;  //i2c dma rx structure
extern DMA_HandleTypeDef hdma_i2c2_tx;  //i2c dma tx structure
extern I2C_HandleTypeDef hi2c2;

/* function that holds all of the other functions */
void initEverythig(void);

/* configures low level settings */
void SystemClock_Config(void);
void Error_Handler(void);

/* configures the pwm for the blue esc hydraulics motor */
void initPwm(void);

/* configures I2C with DMA */
void initI2C(void);

/* configures can and sets up an interrupt for received data */
void initCan(void);

/* test can initialization */
HAL_StatusTypeDef CAN_init(void);

void MX_DMA_Init(void);

//initializes nested vector interrupt handlers
void HAL_MspInit(void);

void MX_I2C2_Init(void);

/*function for initializing and using leds */
void initDebugLeds(void);
void LedOn(int ledNum);
void LedOff(int ledNum);
void LedToggle(int ledNum);




#endif