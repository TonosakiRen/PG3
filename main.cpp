#include<stdio.h>
#include <iostream>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <functional>
#include <numbers>

class IShape {
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
};

class Circle :
public IShape
{
public:
	Circle(float radius);
	void Size() override;
	void Draw() override;
private:
	float radius_;
	float size_;
};

Circle::Circle(float radius) {
	radius_ = radius;
	Size();
}

void Circle::Size() {
	size_ = radius_ * radius_ * 3.14159f;
}

void Circle::Draw() {
	std::cout << "この円の面積は" << size_ << std::endl;
}


class RectAngle :
	public IShape
{
public:
	RectAngle(float width, float height);
	void Size() override;
	void Draw() override;
private:
	float width_;
	float height_;
	float size_;
};

RectAngle::RectAngle(float width, float height) {
	width_ = width;
	height_ = height;
	Size();
}

void RectAngle::Size() {
	size_ = width_ * height_;
}

void RectAngle::Draw() {
	std::cout << "この矩形の面積は" << size_ << std::endl;
}

int main() {
	IShape* iShapes[2];
	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			iShapes = new Circle(20.0f);
		}
		if (i < 2) {
			iShapes = new Circle(20.0f);
		}
	}
	return 0;
}

