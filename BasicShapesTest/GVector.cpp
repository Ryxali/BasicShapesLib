#include "GVector.h"


GVector::GVector(float x, float y) : m_Vector(x, y) {

}
GVector::GVector(const PointProtocol& point) : m_Vector(point.getX(), point.getY()) {

}

GVector::~GVector(void) {
	m_Vector.x = 0;
	m_Vector.y = 0;
}

float GVector::getX() const {
	return m_Vector.x;
}
float GVector::getY() const {
	return m_Vector.y;
}
void GVector::setX(float x) {
	m_Vector.x = x;
}
void GVector::setY(float y) {
	m_Vector.y = y;
}