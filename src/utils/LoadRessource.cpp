// LoadRessource.cpp
// Load in one fonction the ressource

#include "LoadRessource.hpp"

// Namespace for more manipulation
namespace LoadRessource {
    // Loading music
    // @param: the music on where to load it, the file on where is the music
    // @return: true id its load, throw exception if not
    bool loadMusic(const std::string& filePath, sf::Music& music) {
        if (!music.openFromFile(filePath)) {
            throw std::runtime_error("Failed to load: " + filePath);
        }
        return true;
    }

    // Loading font
    // @param : the file path to the font
    // @return: font
    sf::Font loadFont(const std::string& filePath) {
        sf::Font font;

        if (!font.loadFromFile(filePath)) {
            throw std::runtime_error("Failes to load: " + filePath);
        }

        return font;
    }
};