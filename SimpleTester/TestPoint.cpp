#include "TestPoint.h"


TestPoint::TestPoint(const float x, const float y) : mX(x), mY(y) {

}
TestPoint::TestPoint(const TestPoint &point) : mX(point.getX()), mY(point.getY()) {

}
TestPoint::TestPoint(const PointProtocol &point) : mX(point.getX()), mY(point.getY()) {

}

TestPoint::~TestPoint(void) {
	mX = 0;
	mY = 0;
}

float TestPoint::getX() const {
	return mX;
}
float TestPoint::getY() const {
	return mY;
}
void TestPoint::setX(float x) {
	mX = x;
}
void TestPoint::setY(float y) {
	mY = y;
}

