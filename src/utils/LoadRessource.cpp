#include "LoadRessource.hpp"

namespace LoadRessource {
    bool loadMusic(const std::string& filePath, sf::Music& music) {
        if (!music.openFromFile(filePath)) {
            throw std::runtime_error("Failed to load: " + filePath);
        }
        return true;
    }

    sf::Font loadFont(const std::string& filePath) {
        sf::Font font;

        if (!font.loadFromFile(filePath)) {
            throw std::runtime_error("Failes to load: " + filePath);
        }

        return font;
    }
};