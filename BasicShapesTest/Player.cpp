#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include "putils.h"

Player::Player() : Circle(32.f),
	m_position(0, 0), shp(32.f) {
		shp.setFillColor(sf::Color(255, 0, 0, 255));
}

Player::~Player()
{
}

float Player::getCenterX() const {
	return m_position.getX();
}

float Player::getCenterY() const {
	return m_position.getY();
}

void Player::update(std::vector<Entity*> &ents)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		// Walking left!
		m_position.setX(m_position.getX()-1);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		// Walking right!
		m_position.setX(m_position.getX()+1);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		// Walking left!
		m_position.setY(m_position.getY()-1);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		// Walking right!
		m_position.setY(m_position.getY()+1);
	}
	shp.setPosition(getCenterX()-shp.getRadius(), getCenterY()-shp.getRadius());
}

const GVector& Player::getPosition() const {
	return m_position;
}

void Player::render(sf::RenderWindow &win) const {
	win.draw(shp);
}

// true if the shape contains given PointProtocol
bool Player::contains(const PointProtocol &point) const {
	return Circle::contains(point);
}
// true if this shape intersects with given shape
bool Player::intersects(const Shape &shape) const {
	return Circle::intersects(shape);
}
// true if this shape completely envelops given shape
bool Player::envelops(const Shape &shape) const {
	return Circle::envelops(shape);
}
// returns the Point closest to the given shape that's still within this shape
Point Player::getClosestPoint(const Shape &shape) const {
	return Circle::getClosestPoint(shape);
}
// returns the Point farthest from the given shape that's still within this shape
Point Player::getFarthestPoint(const Shape &shape) const {
	return Circle::getFarthestPoint(shape);
}