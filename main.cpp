#include <stdio.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::string> split(std::string& input, char delimiter) {
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (getline(stream, field, delimiter)) result.push_back(field);
	return result;
}
int main() {

	std::mutex mutex;
	std::condition_variable condition;
	std::queue<int> q;
	bool exit = false;
	bool isLoaded = false;

	std::vector<std::vector<int>> data;


	std::thread th([&]() {
		std::unique_lock<std::mutex> uniqueLock(mutex);
		while (!exit) {
			if (q.empty()) {
				condition.wait(uniqueLock);
			}
			else {
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				q.pop();
				std::ifstream ifs("map.csv");
				std::string line;

				while (std::getline(ifs, line)) {
					std::vector<int> dataVec;
					std::vector<std::string> strVec = split(line, ',');
					for (auto&& s : strVec) dataVec.push_back(std::stoi(s));
					data.push_back(dataVec);
				}

				isLoaded = true;
			}
		}
	});


	//gameループ
	while (true) {
		//mapChipの読み込み(非同期)
		
		if (!isLoaded) {
			//読み込み処理
			std::cout << "NowLoading";
			q.push(2);
			condition.notify_all();
			while (!isLoaded) {
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				std::cout << ".";
			}
			std::cout << std::endl;
		}

		//mapChipの処理
		//th.join();
		for (int y = 0; y < data.size();y++) {
			for (int x = 0; x < data[y].size();x++) {
				std::cout << data[y][x] << ",";
			}
			std::cout << std::endl;
		}

		break;
	}
	th.join();
	exit = true;
	return 0;
}

