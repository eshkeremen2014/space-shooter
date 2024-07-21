#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include"meteor.h"
#include <list>
#include "textureManager.h"
class Meteor_manager {
private:
	std::list<Meteor*> meteors;
	TextureManager& tManager;
	std::list <std::string> images; 
public:
	Meteor_manager(TextureManager& tM) :images{ "meteorBrown_big1.png", "meteorBrown_big2.png", "meteorBrown_big3.png", "meteorBrown_big4.png",
	"meteorBrown_med1.png","meteorBrown_med3.png","meteorBrown_small1.png","meteorBrown_small2.png",
	"meteorBrown_tiny1.png","meteorBrown_tiny2.png"
	}, tManager(tM){
		for (auto& file_name : images) {
			
			Meteor* meteor = new Meteor("images/"+file_name);
			setRandPos(meteor);
			meteors.push_back(meteor);
			if (file_name.find("big") != std::string::npos) {
				meteor->setDamag(80);
			}
			else if (file_name.find("med") != std::string::npos) {
				meteor->setDamag(50);
			}
			else if (file_name.find("smal") != std::string::npos) {
				meteor->setDamag(20);
			}
			else if (file_name.find("tiny") != std::string::npos) {
				meteor->setDamag(10);
			}
		}

	}
	void setRandPos(Meteor*meteor) {
		int speedY = rand() % 6 + 3;
		int speedX = rand() % 5 - 2;
		float x = rand() % SCREEN_WIDTH;
		float y = -(rand() % (SCREEN_HEIGHT / 2));
		meteor->setPosition(x,y);
		meteor->setSpeed(speedX,speedY);
	}
	void update() {
		for (auto& meteor : meteors) {
			meteor->update();
			if (meteor->getPosition().y > SCREEN_HEIGHT || meteor->getPosition().x > SCREEN_WIDTH ||
				meteor->getPosition().x < -meteor->getHitBox().width) {
				int speedY = rand() % 6 + 3;
				int speedX = rand() % 5 - 2;
				float x = rand() % SCREEN_WIDTH;
				float y = -(rand() % (SCREEN_HEIGHT / 2));
				meteor->setSpeed(speedX, speedY);
				meteor->setPosition(x, y);
			}
		}

	}
	void draw(sf::RenderWindow& window) {
		for (auto& meteor : meteors) {
			meteor->draw(window);
		}
	}
	std::list<Meteor*>* getMeteors() {
		return & meteors;
	}
};

