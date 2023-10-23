#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>

class Animal {
public:
	Animal(const char* name);
	~Animal();
	virtual void Cry() = 0;
protected:
	std::string name_;
};
Animal::Animal(const char* name) {
	name_ = name;
}
Animal::~Animal() {
	std::cout << name_ << "は死んだ" << std::endl;
}

class Cat 
	: public Animal
{
public:
	using Animal::Animal;
	void Cry() override;

};
void Cat::Cry() {
	std::cout << name_ << "は「ニャー」と鳴いた" << std::endl;
}

class Dog
	: public Animal
{
public:
	using Animal::Animal;
	void Cry() override;

};

void Dog::Cry() {
	std::cout << name_ << "は「ワン」と鳴いた" << std::endl;
}

int main() {
	Animal* animals[2];
	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			animals[i] = new Cat("たま");
		}
		else {
			animals[i] = new Dog("ぽち");
		}
	}
	for (int i = 0; i < 2; i++) {
		animals[i]->Cry();
	}
	for (int i = 0; i < 2; i++) {
		delete animals[i];
	}

	return 0;
}

