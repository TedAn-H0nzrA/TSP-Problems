#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace Constants {
    inline sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    inline float WIDTH = static_cast<float>(desktop.width);
    inline float HEIGHT = static_cast<float>(desktop.height);
    inline std::string TITLE = "TSP problems (BruteForce vs ACO)";
    inline sf::Color BACKGROUND_COLOR {30, 30, 45};
    inline std::string BACKGROUND_MUSIC = std::string(MUSICS_DIR) + "/background_music.ogg";
    inline constexpr float bg_music_volume = 15;

    // Town
    inline constexpr float t_radius = 10;
    inline sf::Color t_color{255, 215, 0};
};