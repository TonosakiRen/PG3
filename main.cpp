#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
int SpCalculationHourly(int hourly,int hours) {
	assert(hours < 0);
	if (hours <= 0) {
		return 0;
	}
	return  hourly + SpCalculationHourly(hourly * 2 - 50, hours - 1);
}

int CalculationHourly(int hourly, int hours) {
	assert(hours < 0);
	return hours * hourly;
}

template <typename Type>
void Print(Type a) {
	std::cout << typeid(Type).name() << ":" << a << "\n";
}
template <>
void Print<char>(char a) {
	std::cout << "数字以外は代入できません" << "\n";
}

int main() {
	int a = SpCalculationHourly(100,5);
	int b = CalculationHourly(1072, 5);
	int diff = abs(a - b);
	if (a < b) {
		std::cout << b << "円で普通賃金体系のほうが";
	}
	else {
		std::cout << a << "円で特殊賃金体系のほうが";
	}	

	return 0;
}

