#pragma once
#include "PointProtocol.h"
class TestPoint : public PointProtocol {
public:
	TestPoint(const float x, const float y);
	TestPoint(const TestPoint &point);
	TestPoint(const PointProtocol &point);
	~TestPoint();

	virtual float getX() const;
	virtual float getY() const;

	virtual void setX(float x);
	virtual void setY(float y);
private:
	float mX, mY;
};

