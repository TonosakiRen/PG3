#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>

int Rand(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

typedef void (*Pfunc)(bool,int);


void Result(bool isEven, int answer) {
	int answerRemainder = answer % 2;
	if (isEven == true && answerRemainder == 0) {
		std::cout << "正解！" << std::endl;
	}
	else if (isEven == true && answerRemainder == 1) {
		std::cout << "不正解！" << std::endl;
	}
	else if (isEven == false && answerRemainder == 0) {
		std::cout << "不正解！" << std::endl;
	}
	else if (isEven == true && answerRemainder == 1) {
		std::cout << "正解！" << std::endl;
	}
	std::cout << "答えは" << answer << std::endl;
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	while (true) {
		int randNum = Rand(0, 6);
		int isEven = 0;
		while (true) {
			std::cout << "偶数なら１、奇数なら０を入力してください" << std::endl;
			scanf_s("%d", &isEven);
			if (isEven == 0 || isEven == 1) {
				break;
			}
		}
		std::function<void(int)> fx = [](int second) {Sleep(second * 1000); };
		fx(3);
		Result(static_cast<bool>(isEven), randNum);
	}
	return 0;
}

