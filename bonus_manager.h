#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include"bonus.h"
#include <vector>
#include "textureManager.h"
class Bonus_manager {
private:
	std::list<Bonus*>bonuses ;
	TextureManager& tManager;
	std::vector <std::string> images;
public:
	Bonus_manager(TextureManager& tM,float x,float y) :tManager(tM),images{ "bolt_gold(1).png","bolt_gold(2).png","bolt_gold(3).png","bolt_gold(4).png" }
	{
	int spawn=rand() %100;
	Bonus* bonus;
	if (spawn >= BONUS_CHANCE) {
		int bonus_tipe= rand() % 4;
		switch (bonus_tipe) {
		case 0:
			bonus = new Bonus("images/" + images[0]);
			break;
		case 1:
			bonus = new Bonus("images/" + images[1]);
			break;
		case 2:
			bonus = new Bonus("images/" + images[2]);
			break;
		case 3:
			bonus = new Bonus("images/" + images[3]);
			break;
		}
		bonus->setPosition(x,y);
		bonuses.push_back(bonus);
	}
		
	}
	
	/*void setRandPos(Meteor* meteor) {
		int speedY = rand() % 6 + 3;
		int speedX = rand() % 5 - 2;
		float x = rand() % SCREEN_WIDTH;
		float y = -(rand() % (SCREEN_HEIGHT / 2));
		meteor->setPosition(x, y);
		meteor->setSpeed(speedX, speedY);
	}*/
	void dellite() {
		bonuses.remove_if([](Bonus* bonus) {return bonus->getDel(); });
	}
	void update() {
		for (auto& bonus : bonuses) {
			bonus->update();
			if (bonus->getPosition().y > SCREEN_HEIGHT) {
				bonus->setDel();
			}
		}
		dellite();
	}
	void draw(sf::RenderWindow& window) {
		for (auto& bonus : bonuses) {
			bonus->draw(window);
		}
	}
	/*std::list<Meteor*>* getMeteors() {
		return &meteors;
	}*/
};
