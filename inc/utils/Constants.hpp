#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Constants {
    inline sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    inline float WIDTH = static_cast<float>(desktop.width);
    inline float HEIGHT = static_cast<float>(desktop.height);
    inline std::string TITLE = "TSP problems (BruteForce vs ACO)";
    inline sf::Color BACKGROUND_COLOR {30, 30, 45};
};