#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {

	std::string filePath = "PG3_05_02.txt";

    std::ifstream file(filePath);

    std::string line;

    std::vector<std::string> ids;

    while (std::getline(file, line)) {
       
        std::istringstream iss(line);
        std::string id;

        while (std::getline(iss, id, ',')) {
            ids.push_back(id);
        }

    }

    // ファイルを閉じる
    file.close();

	return 0;
}

