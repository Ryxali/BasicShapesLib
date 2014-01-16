#pragma once
#include "Entity.h"
#include "Rectangle.h"
#include "GVector.h"
#include <SFML/Graphics/RectangleShape.hpp>

class CollisionEntity : public Entity, public Rectangle {
public:

	CollisionEntity(void);
	~CollisionEntity(void);
	virtual void update(std::vector<Entity*> &ents);
	virtual void render(sf::RenderWindow &win) const;
	virtual float getCenterX() const;
	virtual float getCenterY() const;

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

	sf::RectangleShape shp;
private:
	GVector m_position;
	
};

