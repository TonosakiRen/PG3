#pragma once
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include<cstdlib>
#include <ctime>

void END() {
	int num = 0;
	while (num != 1) {
		printf("\n�R���\�[���A�v���P�[�V�������I������ꍇ�͐����̂P����͂�Enter�L�[�������Ă�������\n");
		scanf_s("%d", &num);
	}

}

/// <summary>
/// ����
/// </summary>
/// <param name="min">�ŏ��l</param>
/// <param name="max">�ő�l</param>
/// <returns>int�^</returns>
int RAND(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
//srand((unsingned)time(NULL));