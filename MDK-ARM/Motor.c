
#include "stm32f4xx_hal.h"
#include "main.h"
#include "string.h"

extern TIM_HandleTypeDef htim2;

// Sets the Right and Left pwm of bts7960 module ON.
void motor_Enable() {
		HAL_GPIO_WritePin(R_EN_GPIO_Port,R_EN_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(L_EN_GPIO_Port,L_EN_Pin,GPIO_PIN_SET);
}

// Sets the Right and Left pwm of bts7960 module OFF.
void motor_Disable() {
		HAL_GPIO_WritePin(R_EN_GPIO_Port,R_EN_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(L_EN_GPIO_Port,L_EN_Pin,GPIO_PIN_RESET);
}

//Sets clockwis motion.
void motor_Forward(int pwm) {
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,pwm);
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,0);
}

//Sets anticlockwis motion.
void motor_Reverse(int pwm) {
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_1,0);
		__HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_2,pwm);
}

//Checks status to set pwm.
void check_Motor(int status, int pwm) {
		switch ((status)) {
			case 0 :
				motor_Reverse(0);
				motor_Forward(0);
				motor_Disable();
				break;
			case 1 :
				motor_Enable();
				motor_Forward(pwm);
				break;
			case 2 :
				motor_Enable();
				motor_Reverse(pwm);

		}
}