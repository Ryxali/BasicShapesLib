#include "TestCircle.h"


TestCircle::TestCircle(float radius, TestPoint center) : Circle(radius), mCenter(center) {

}


TestCircle::~TestCircle(void) {

}

float TestCircle::getCenterX() const {
	return mCenter.getX();
}

float TestCircle::getCenterY() const {
	return mCenter.getY();
}