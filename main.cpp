#include"main.h"
#include <iostream>
template <typename Type>
Type min(Type a, Type b) {
	return   a < b ? a : b;
 }
template <typename Type>
void PrintMin(Type a) {
	std::cout << typeid(Type).name() << ":" << a << "\n";
}
template <>
void PrintMin<char>(char a) {
	std::cout << "”ŽšˆÈŠO‚Í‘ã“ü‚Å‚«‚Ü‚¹‚ñ" << "\n";
}

int main() {
	PrintMin(min(3, 3));
	PrintMin(min(3.0f, 3.0f));
	PrintMin(min(3.0, 3.0));
	PrintMin(min('a', 'v'));
	END();
	return 0;
}

