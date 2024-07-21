#include"settings.h"
#include"laser.h"
#include<list>
#include"player.h"

	void Laser_manager:: create_laser(Player& player) {
		Laser* laser = new Laser();
		sf::Vector2f player_position = player.getPosition();
		float laser_x = player_position.x + player.getHitBox().width / 2;
		float laser_y = player_position.y - player.getHitBox().height;
		laser->setPosition(laser_x, laser_y);
		lasers.push_back(laser);
	}
	void Laser_manager::update() {
		for (auto& laser : lasers) {
			laser->update();
		}
		lasers.remove_if([](Laser* laser) {return laser->getPosition().y < -laser->getHitBox().height; });
	}
	void Laser_manager::draw(sf::RenderWindow& window) {
		for (auto& laser : lasers) {
			laser->draw(window);
		}
	}
	std::list<Laser*>* Laser_manager::getLasers() {
		return & lasers;
	}
	void Laser_manager::dellite() {
		lasers.remove_if([](Laser* laser) {return laser->getDel();});
	}
