#pragma once
#include <SFML/Graphics.hpp>
class Laser {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int speedY=-10;
public:
	Laser() {
		texture.loadFromFile("iamges/laserBlue12.png");
		sprite.setTexture(texture);
	}
	void setPosition(float x,float y) {
		sprite.setPosition(x, y);
	}
	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void update() {
		sprite.move(0, speedY);
	}
};