#include "Ent.h"


Ent::Ent(float radius, GVector pos) : Circle(radius), pos(pos), shp(radius) {
	shp.setFillColor(sf::Color(0, 255, 0, 255));
}
Ent::~Ent() {

}

float Ent::getCenterX() const {
	return pos.getX();
}
float Ent::getCenterY() const {
	return pos.getY();
}
void Ent::setCenterY(float y) {
	pos.setY(y);
}
void Ent::setCenterX(float x) {
	pos.setX(x);
}

void Ent::render(sf::RenderWindow &win) const {
	win.draw(shp);
}
