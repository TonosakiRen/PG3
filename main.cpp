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
#include <regex>

int main() {

    struct account {
        std::string id;
        int era_number;
    };

	std::string filePath = "PG3_05_02.txt";

    std::ifstream file(filePath);

    std::string line;

    std::vector<account> accounts;

    std::regex pattern(R"(k(\d+)g(\d+)@g.neec.ac.jp)");

    std::string id;

    while (std::getline(file, id, ',')) {
        std::smatch match;
        int era_number = 0;
        if (std::regex_search(id, match, pattern)) {
            era_number = std::stoi(match[1].str() + match[2].str());
        }
        accounts.push_back({ id,era_number });
    }

    file.close();

    std::sort(accounts.begin(), accounts.end(), [](const account& a, const account& b) {
        return a.era_number < b.era_number;
    });

    for (auto& account : accounts) {
        std::cout << account.id << std::endl;
    }

	return 0;
}

