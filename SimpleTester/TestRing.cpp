#include "TestRing.h"


TestRing::TestRing(float radius, float holeRadius, TestPoint center) : Ring(radius, holeRadius), mCenter(center) {

}
TestRing::~TestRing() {

}

float TestRing::getCenterX() const {
	return mCenter.getX();
}
float TestRing::getCenterY() const {
	return mCenter.getY();
}
