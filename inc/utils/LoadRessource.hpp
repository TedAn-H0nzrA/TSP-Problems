#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

namespace LoadRessource{
    bool loadMusic(const std::string& filePath, sf::Music& music);

    sf::Font loadFont(const std::string& filePath);
};