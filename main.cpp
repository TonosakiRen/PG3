#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>

class Enemy {
public:
	void Update();
	void Approach();
	void Shoot();
	void Retreat();
	enum Stats {
		approach,
		shoot,
		retreat,

		statsNum
	};
	Stats stats_ = approach;
	int frame_ = 0;
private:
	static void (Enemy::*spFuncTable[])();
};

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::Retreat
};

void Enemy::Update() {
	frame_++;
	if (frame_ % 60 == 0) {
		if (static_cast<int>(statsNum) == static_cast<Stats>(static_cast<int>(stats_) + 1)) {
			stats_ = static_cast<Stats>(0);
		}
		else {
			stats_ = static_cast<Stats>(static_cast<int>(stats_) + 1);
		}
	}
	(this->*spFuncTable[static_cast<size_t>(stats_)])();

}
void Enemy::Approach() {
	std::cout << "接近中" << std::endl;
}
void Enemy::Shoot() {
	std::cout << "射撃中" << std::endl;
}
void Enemy::Retreat() {
	std::cout << "離脱中" << std::endl;
}

int main() {
	Enemy enemy;
	while (true) {
		enemy.Update();
		if (enemy.frame_ >= 1000) {
			break;
		}
	}
	return 0;
}

