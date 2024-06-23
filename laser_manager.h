#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include"laser.h"
#include<list>
#include"player.h"
class Laser_manager {
private:
	std::list<Laser*>lasers;
	Player player;
public:
	Laser_manager(Player p):player(p){
		
	}
	void create_laser() {
		Laser* laser= new Laser();
		sf::Vector2f player_position=player.getPosition();
		float laser_x = player_position.x + player.getHitBox().width / 2;
		float laser_y = player_position.y - player.getHitBox().height;
		laser->setPosition(laser_x, laser_y);
		lasers.push_back(laser);
	}
	void update() {
		for (auto& laser : lasers) {
			laser->update();
		}
		lasers.remove_if([](Laser* laser) {return laser->getPosition().y < -laser->getHitBox().height; });
	}
	void draw(sf::RenderWindow& window){
		for (auto& laser : lasers) {
			laser->draw(window);
		}
	}
};