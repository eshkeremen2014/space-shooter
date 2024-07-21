#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include "player.h"
#include"meteor_manager.h"
#include"TextureManager.h"
#include"laser_manager.h"
#include"text_obj.h"
class Game {
public:
	enum GameState {
		PLAY, GAME_OVER
	};
	Game() :window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), TITLE), meteor_manager(tx),
		textObj("DS-DIGIT.TTF", 32, 5, 5,sf::Color::White ),
		playerHpText("DS-DIGIT.TTF", 32, SCREEN_WIDTH-15, 5, sf::Color::White)
	{
		window.setFramerateLimit(FPS);
	}

	void play() {
		while (window.isOpen()&&game_state==PLAY)
		{
			checkEvents();
			update();
			checkColisions();
			draw();
		}
	}
private:
	sf::RenderWindow window;
	Player player;
	Meteor_manager meteor_manager;
	TextureManager tx;
	Laser_manager l_m;
	GameState game_state=PLAY;
	TextObject  textObj;
	TextObject playerHpText;
	int score = 0;
	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	
	void update(){
		switch (game_state) {
		case PLAY:
			player.update(l_m);
			meteor_manager.update();
			l_m.update();
			textObj.update(std::to_string(score));
			playerHpText.update(std::to_string(player.getHp()));
			break;
		case GAME_OVER:
			break;
		}
	}
	void checkColisions() {
		for (auto& meteor : (*meteor_manager.getMeteors())) {
			if (meteor->getHitBox().intersects(player.getHitBox())) {
				player.reduseHP(meteor->getDamag());
				meteor_manager.setRandPos(meteor);
				if (player.getHp() <= 0) {
					game_state = GAME_OVER;
				}
			}
			for (auto& laser : (*l_m.getLasers())) {
				if (meteor->getHitBox().intersects(laser->getHitBox())) {
					meteor_manager.setRandPos(meteor);
					score++;
					laser->setDel();
				}
			}
			l_m.dellite();
		}

	}
	void draw() {
		window.clear();
		player.draw(window);
		meteor_manager.draw(window);
		l_m.draw(window);
		textObj.draw(window);
		playerHpText.draw(window);
		window.display();
		
		
	}
	

};
