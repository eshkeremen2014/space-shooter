#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include <list>
class Bonus {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int speedY=3;
	bool isToDel = false;
public:
	Bonus(std::string texture_file_name) {
		texture.loadFromFile(texture_file_name);
		sprite.setTexture(texture);
	}
	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	void setSpeed( int speedY) {
		this->speedY = speedY;
	}
	void setPosition(float x, float y) {
		sprite.setPosition(x, y);
	}
	void update() {
		sprite.move(0, speedY);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void setDel() {
		isToDel = true;
	}
	bool getDel() {
		return isToDel;
};
