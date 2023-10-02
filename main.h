#pragma once
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>
#include<cstdlib>
#include <ctime>

void END() {
	int num = 0;
	while (num != 1) {
		printf("\nコンソールアプリケーションを終了する場合は数字の１を入力しEnterキーを押してください\n");
		scanf_s("%d", &num);
	}

}

/// <summary>
/// 乱数
/// </summary>
/// <param name="min">最小値</param>
/// <param name="max">最大値</param>
/// <returns>int型</returns>
int RAND(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}
//srand((unsingned)time(NULL));