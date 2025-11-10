
#include "stm32f4xx_hal.h"

void motor_Enable();
void motor_Disable();
void motor_Forward(int pwm);
void motor_Reverse(uint8_t pwm);
void check_Motor(int status,int pwm);