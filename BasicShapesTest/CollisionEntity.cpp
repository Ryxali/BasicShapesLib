#include "CollisionEntity.h"
#include <SFML/Window.hpp>
#include "putils.h"

CollisionEntity::CollisionEntity(void) : Rectangle(96.f, 96.f), shp(sf::Vector2f(96.f, 96.f)), m_position(128, 128) {

	shp.setFillColor(sf::Color(0, 255, 0, 255));
}

CollisionEntity::~CollisionEntity(void) {

}

float CollisionEntity::getCenterX() const {
	return m_position.getX();
}

float CollisionEntity::getCenterY() const {
	return m_position.getY();
}
void CollisionEntity::update(std::vector<Entity*> &ents) {
	for(std::vector<Entity*>::iterator it = ents.begin(); it != ents.end(); it++) {
		if(*it != this){
			if(intersects(*(*it))) {
				if(envelops(*(*it))) {
					shp.setFillColor(sf::Color(255, 255, 255, 100));
				} else {
					shp.setFillColor(sf::Color(0, 0, 255, 255));
				}
			} else {
				shp.setFillColor(sf::Color(0, 255, 0, 255));
			}
		}
	}
	shp.setPosition(getCenterX()-shp.getSize().x/2, getCenterY()-shp.getSize().y/2);
}
void CollisionEntity::render(sf::RenderWindow &win) const {
	win.draw(shp);
}

// true if the shape contains given PointProtocol
bool CollisionEntity::contains(const PointProtocol &point) const {
	return Rectangle::contains(point);
}
// true if this shape intersects with given shape
bool CollisionEntity::intersects(const Shape &shape) const {
	return Rectangle::intersects(shape);
}
// true if this shape completely envelops given shape
bool CollisionEntity::envelops(const Shape &shape) const {
	return Rectangle::envelops(shape);
}
// returns the Point closest to the given shape that's still within this shape
Point CollisionEntity::getClosestPoint(const Shape &shape) const {
	return Rectangle::getClosestPoint(shape);
}
// returns the Point farthest from the given shape that's still within this shape
Point CollisionEntity::getFarthestPoint(const Shape &shape) const {
	return Rectangle::getFarthestPoint(shape);
}