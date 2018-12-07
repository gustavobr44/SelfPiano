#ifndef PIANO_H_
#define PIANO_H_

#include "main.h"
#include "TecladoFuncoes.h"

void buzzerOn(TIM_HandleTypeDef *tim);
void buzzerOff(TIM_HandleTypeDef *tim);
void buzzerFreq(TIM_HandleTypeDef *tim, int freq);

void userToca(TIM_HandleTypeDef *buzzer, unsigned long *tecladoOut, unsigned long *tecladoIn, int N, int M);

void servoAngle(TIM_HandleTypeDef *tim, int angle);

void teclaSelect(TIM_HandleTypeDef *tim, int tecla);
void teclaToca(TIM_HandleTypeDef *tim);
void pianoToca(TIM_HandleTypeDef *select, TIM_HandleTypeDef *touch, int *tecla, int N);

#endif /* PIANO_H_ */
