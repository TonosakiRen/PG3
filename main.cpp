#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>
template <typename T1,typename T2,typename T3 = T1>
class Comparison {
public:
	Comparison(T1 a, T2 b) : a_(a), b_(b) {
	};

	T1 Min() {
		if (a_ < b_) {
			return static_cast<T3>(a_);
		}
		return static_cast<T3>(b_);
	};

	T1 a_;
	T2 b_;
};

int main() {
	Comparison<int,int> intint(2,3);
	Comparison<int, float> intfloat(2, 3.0f);
	Comparison<int, double> intdouble(2, 3.0);
	Comparison<float, float> floatfloat(2.0f, 3.0f);
	Comparison<double, float> doublefloat(2.0, 3.0f);

	std::cout<< intint.Min() << std::endl;
	std::cout << intfloat.Min() << std::endl;
	std::cout << intdouble.Min() << std::endl;
	std::cout << floatfloat.Min() << std::endl;
	std::cout << doublefloat.Min() << std::endl;

	return 0;
}

