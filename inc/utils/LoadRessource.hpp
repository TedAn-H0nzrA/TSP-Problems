// LoadRessource.hpp
// Isolation of the load in namespace so its have more manipulation

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

// Namespace LoadRessource for charging specific ressource
namespace LoadRessource{
    bool loadMusic(const std::string& filePath, sf::Music& music);

    sf::Font loadFont(const std::string& filePath);
};