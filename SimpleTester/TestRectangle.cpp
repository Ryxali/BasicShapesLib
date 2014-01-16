#include "TestRectangle.h"


TestRectangle::TestRectangle(float width, float height, TestPoint center) : Rectangle(width, height), mCenter(center) {

}
TestRectangle::~TestRectangle() {

}
float TestRectangle::getCenterX() const {
	return mCenter.getX();
}
float TestRectangle::getCenterY() const {
	return mCenter.getY();
}