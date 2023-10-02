#include <iostream>
template <typename Type>
Type min(Type a, Type b) {
	return   a < b ? a : b;
 }
template <typename Type>
void Print(Type a) {
	std::cout << typeid(Type).name() << ":" << a << "\n";
}
template <>
void Print<char>(char a) {
	std::cout << "数字以外出力できません" << "\n";
}

int main() {
	Print(min(3, 3));
	Print(min(3.0f, 3.0f));
	Print(min(3.0, 3.0));
	Print(min('a', 'v'));
	return 0;
}

