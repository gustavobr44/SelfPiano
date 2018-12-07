#include "Piano.h"

void buzzerOn(TIM_HandleTypeDef *tim) {
	tim->Instance->CCR1 = 500;
}

void buzzerOff(TIM_HandleTypeDef *tim) {
	tim->Instance->CCR1 = 0;
}

void buzzerFreq(TIM_HandleTypeDef *tim, int freq) {
	tim->Instance->PSC = (int) 8000000 / (freq * 1000);
}

void userToca(TIM_HandleTypeDef *buzzer, unsigned long *tecladoOut,
		unsigned long *tecladoIn, int N, int M) {
	int freqs[7] = { 440, 495, 528, 594, 660, 704, 792 };
	int digito = scanForClick(tecladoOut, tecladoIn, N, M);

	while (digito != 9) {
		if (digito <= 7) {
			buzzerFreq(buzzer, freqs[digito - 1]);
			buzzerOn(buzzer);

			while (colPressed(tecladoIn, 3) != -1)
				;

			buzzerOff(buzzer);
		}

		digito = scanForClick(tecladoOut, tecladoIn, N, M);
	}
}

void servoAngle(TIM_HandleTypeDef *tim, int angle) {
	tim->Instance->CCR1 = (int) (75 * angle + 4500) / 180;
}

void teclaSelect(TIM_HandleTypeDef *tim, int tecla) {
	switch (tecla) {
	case 1:
		servoAngle(tim, 0);
		break;
	case 2:
		servoAngle(tim, 20);
		break;
	case 3:
		servoAngle(tim, 40);
		break;
	case 4:
		servoAngle(tim, 60);
		break;
	case 5:
		servoAngle(tim, 80);
		break;
	case 6:
		servoAngle(tim, 100);
		break;
	case 7:
		servoAngle(tim, 120);
		break;
	}
}

void teclaToca(TIM_HandleTypeDef *tim) {
	tim->Instance->CCR1 = 90;
	HAL_Delay(500);
	tim->Instance->CCR1 = 0;
}

void pianoToca(TIM_HandleTypeDef *select, TIM_HandleTypeDef *touch, int *tecla,
		int N) {
	for (int i = 0; i < N; i++) {
		teclaSelect(select, tecla[i]);
		HAL_Delay(1000);
		teclaToca(touch);
		HAL_Delay(500);
	}
}
