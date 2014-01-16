#pragma once

#include "Ring.h"
#include "TestPoint.h"

class TestRing : public Ring {
public:
	TestRing(float radius, float holeRadius, TestPoint center);
	~TestRing();

	virtual float getCenterX() const;
	virtual float getCenterY() const;
protected:
	TestPoint mCenter;
};

