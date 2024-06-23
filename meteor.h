#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include <list>
class Meteor {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int speedX;
	int speedY;
	
public:
	Meteor(float x, float y,int speedX,int speedY, std::string texture_file_name) {
		texture.loadFromFile(texture_file_name);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);

	}
	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	void setSpeed(int speedX, int speedY) {
		this->speedX = speedX;
		this->speedY = speedY;
	}
	void setPosition(float x, float y) {
		sprite.setPosition(x, y);
	}
	void update() {
		sprite.move(speedX, speedY);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};