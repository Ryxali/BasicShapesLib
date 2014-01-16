#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Player.h"
#include "CollisionEntity.h"

int main()
{
	// Create a window with resolution 640x360 and set title to "BasicShapes Demo". Note that this resolution is independent of view-resolution. You can change this and the view will scale up to fit the window. Very handy!
	sf::RenderWindow window(sf::VideoMode(640, 360), "BasicShapes Demo");
	window.setFramerateLimit(60);
	// A view is a simple camera, a "rectangle" which you see through into the world.
	sf::View view;
	view.setSize(640,360);

	// An event can be polled against window. If an event occurs, it will be fille with the event data.
	sf::Event evt;
	sf::CircleShape mousePos;
	mousePos.setFillColor(sf::Color(255, 255, 255, 255));
	mousePos.setRadius(5);

	std::vector<Entity*> ents;
	ents.push_back(new Player());
	CollisionEntity *ent = new CollisionEntity();
	ents.push_back(ent);

	while(window.isOpen())
	{
		// Loop runs through all new events
		while(window.pollEvent(evt))
		{
			// Switch-statements can be used instead of if-statements, good in case we have many eventtypes to handle.
			if(evt.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		for(std::vector<Entity*>::iterator it = ents.begin(); it != ents.end(); it++) {
			(*it)->update(ents);
			
		}
		if(ent->contains(GVector(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {
				mousePos.setFillColor(sf::Color(255, 0, 0, 255));
			}else {
				mousePos.setFillColor(sf::Color(255, 255, 255, 255));
			}
		window.clear();

		// Draw background first, then the player
		for(std::vector<Entity*>::iterator it = ents.begin(); it != ents.end(); it++) {
			(*it)->render(window);
		}
		
		mousePos.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		window.draw(mousePos);
		//window.draw(background);
		
		// Flip buffers
		window.display();
	}

	return 0;
}