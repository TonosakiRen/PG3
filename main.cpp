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
	enum stats {
		approach,
		shoot,
		retreat,

		statsNum
	};

private:
	static void (Enemy::*spFuncTable[])();
};

void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::Retreat
};

void Enemy::Update() {

	(this->*spFuncTable[static_cast<size_t>(approach)]);

}
void Enemy::Approach() {
	std::cout << std::en;
}
void Enemy::Shoot() {

}
void Enemy::Retreat() {

}

int main() {
	
	return 0;
}

