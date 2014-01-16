#pragma once
#include <SFML/System/Vector2.hpp>
#include "PointProtocol.h"
class GVector : public PointProtocol {
public:
	GVector(float x, float y);
	GVector(const PointProtocol &point);
	~GVector();
	virtual float getX() const;
	virtual float getY() const;
	virtual void setX(float x);
	virtual void setY(float y);
private:
	sf::Vector2f m_Vector;
};

