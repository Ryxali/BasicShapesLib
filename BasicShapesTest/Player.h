#pragma once
#include "Entity.h"
#include "Circle.h"
#include "GVector.h"
#include <SFML/Graphics/CircleShape.hpp>

class Player : public Entity, public Circle {
public:
	Player();
	~Player();
	virtual float getCenterX() const;
	virtual float getCenterY() const;
	// Checks input, collision and updates current animation
	virtual void update(std::vector<Entity*> &ents);
	const GVector& getPosition() const;
	virtual void render(sf::RenderWindow &win) const;

	// true if the shape contains given PointProtocol
	virtual bool contains(const PointProtocol &point) const;
	// true if this shape intersects with given shape
	virtual bool intersects(const Shape &shape) const;
	// true if this shape completely envelops given shape
	virtual bool envelops(const Shape &shape) const;
	// returns the Point closest to the given shape that's still within this shape
	virtual Point getClosestPoint(const Shape &shape) const;
	// returns the Point farthest from the given shape that's still within this shape
	virtual Point getFarthestPoint(const Shape &shape) const;

	sf::CircleShape shp;
private:
	GVector m_position;
	
};

