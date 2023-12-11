#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>
#include <list>
#include <string>

int main() {
	std::list <const char*> stationNames;
	const char* str = "AAA";
	stationNames.push_back(str);

	std::cout << stationNames.front() << std::endl;

	return 0;
}

