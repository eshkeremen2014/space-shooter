#pragma once
#include <SFML/Graphics.hpp>
#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include"laser.h"
#include<list>

class Player;

class Laser_manager {
private:
    std::list<Laser*> lasers;
public:
    void create_laser(Player& player);
    void update();
    void draw(sf::RenderWindow& window);
    std::list<Laser*>* getLasers();
    void dellite();
};