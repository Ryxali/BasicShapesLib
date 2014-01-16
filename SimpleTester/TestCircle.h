#pragma once
#include "Circle.h"
#include "TestPoint.h"
class TestCircle : public Circle {
public:
	TestCircle(float radius, TestPoint center);
	~TestCircle();

	virtual float getCenterX() const;
	virtual float getCenterY() const;
private:
	TestPoint mCenter;
};

