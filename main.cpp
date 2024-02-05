#include <iostream>

#include <chrono>
#include <string>

int main() {
    std::string str(1000000, 'a');
    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();

    std::string copy = str;
    std::chrono::microseconds copyTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - time);
    std::cout << copyTime.count() << std::endl;

    time = std::chrono::system_clock::now();

    std::string move = std::move(str);
    std::chrono::microseconds moveTime = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - time);
    std::cout << moveTime.count() << std::endl;

    return 0;
}