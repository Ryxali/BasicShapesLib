#pragma once
#include "Rectangle.h"
#include "TestPoint.h"
class TestRectangle : public Rectangle {
public:
	TestRectangle(float width, float height, TestPoint center);
	~TestRectangle();
	virtual float getCenterX() const;
	virtual float getCenterY() const;
protected:
	TestPoint mCenter;
};

