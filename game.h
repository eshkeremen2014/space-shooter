#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include "player.h"
#include"meteor_manager.h"
#include"TextureManager.h"
#include"laser_manager.h"
class Game {
private:
	sf::RenderWindow window;
	Player player;
	Meteor_manager meteor_manager;
	TextureManager tx;
	Laser_manager l_m;
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	
	void update(){
		player.update(l_m);
		meteor_manager.update();
		l_m.update();
	}
	void checkColisions() {

	}
	void draw() {
		window.clear();
		player.draw(window);
		meteor_manager.draw(window);
		l_m.draw(window);
		window.display();
		
	}
	
public:
	Game() :window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE),meteor_manager(tx),l_m(player) {
		window.setFramerateLimit(FPS);
	}
	
	void play() {
		while (window.isOpen())
		{
			checkEvents();
			update();
			checkColisions();
			draw();
		}
	}
};
