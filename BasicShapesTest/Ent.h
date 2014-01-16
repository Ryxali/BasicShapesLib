#pragma once
#include "Circle.h"
#include "GVector.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Ent : public Circle {
public:
	Ent(float radius, GVector pos);
	~Ent();

	virtual float getCenterX() const;
	virtual float getCenterY() const;
	void setCenterY(float y);
	void setCenterX(float x);

	void render(sf::RenderWindow &win) const;
private:
	GVector pos;
	sf::CircleShape shp;
};

