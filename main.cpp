#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
int SpCalculationHourly(int hourly,int hours) {
	assert(hours >= 0);
	if (hours <= 0) {
		return 0;
	}
	return  hourly + SpCalculationHourly(hourly * 2 - 50, hours - 1);
}

int CalculationHourly(int hourly, int hours) {
	assert(hours >= 0);
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
	for (int i = 0; i < 12; i++) {
		std::cout << i + 1 << "時間の場合" << std::endl;
		int a = SpCalculationHourly(100, i + 1);
		int b = CalculationHourly(1072, i + 1);
		int diff = abs(a - b);
		std::cout << b << "円普通賃貸系" << std::endl;
		std::cout << a << "円特殊賃貸系" << std::endl;
		if (a < b) {
			std::cout << diff << "円普通賃貸系のほうが高い\n\n";
		}
		else {
			std::cout << diff << "円特殊賃貸系のほうが高い\n\n";
		}

	}
	return 0;
}

