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

void SetTime(std::function<void()> func, int second) {
	Sleep(second * 1000);
	func();
}


void Result(bool isEven, int answer) {
	int answerRemainder = answer % 2;
	if (isEven == true && answerRemainder == 0) {
		std::cout << "correct answer!" << std::endl;
	}
	else if (isEven == true && answerRemainder == 1) {
		std::cout << "Incorrect answer!" << std::endl;
	}
	else if (isEven == false && answerRemainder == 0) {
		std::cout << "Incorrect answer!" << std::endl;
	}
	else if (isEven == true && answerRemainder == 1) {
		std::cout << "correct answer!" << std::endl;
	}
	std::cout << "answer is " << answer << std::endl;
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	while (true) {
		int randNum = Rand(0, 6);
		int isEven = 0;
		while (true) {
			std::cout << "Please enter 1 if the number is even, 0 if the number is odd." << std::endl;
			scanf_s("%d", &isEven);
			if (isEven == 0 || isEven == 1) {
				break;
			}
		}
		SetTime([&]() {Result(isEven, randNum); }, 3);
	}
	return 0;
}

