#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include"laser_manager.h"
class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int speedX;
public:
	Player(){
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(SCREEN_WIDTH / 2 - 23, 750);
	}
	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void update(Laser_manager& l_m) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			speedX = -PLAYER_SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			speedX = PLAYER_SPEED;
		}
		sprite.move(speedX, 0);
		speedX = 0;
		if (sprite.getPosition().x <= 0) {
			sprite.setPosition(0, sprite.getPosition().y);
		}
		if (sprite.getPosition().x >= SCREEN_WIDTH - getHitBox().width) {
			sprite.setPosition(SCREEN_WIDTH - getHitBox().width, sprite.getPosition().y);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			 shoot(l_m);
		}
	}
	void shoot(Laser_manager& l_m) {
		l_m.create_laser();
	}
	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
};