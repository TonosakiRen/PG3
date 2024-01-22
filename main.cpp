#include <stdio.h>
#include <thread>
#include <iostream>

void PrintThread(int num) {
	std::cout << "thread " << num << std::endl;
}

int main() {

	std::thread th1(PrintThread, 1);
	th1.join();
	std::thread th2(PrintThread, 2);
	th2.join();
	std::thread th3(PrintThread, 3);
	th3.join();
	return 0;
}

