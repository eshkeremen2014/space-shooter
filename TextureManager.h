#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
public:
    void loadTexture(const std::string& name, const std::string& filename) {
        sf::Texture texture;
        if (texture.loadFromFile(filename)) {
            textures[name] = texture;
        }
    }

    sf::Texture& getTexture(const std::string& name) {
        return textures.at(name);
    }

private:
    std::map<std::string, sf::Texture> textures;
};