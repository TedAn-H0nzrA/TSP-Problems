// Constants.hpp
// Isolating all of the constants value with namespace 
// Option to change value fast

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

// Namespace of all of the const value
namespace Constants {
    inline sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    inline float WIDTH = static_cast<float>(desktop.width);
    inline float HEIGHT = static_cast<float>(desktop.height);
    inline std::string TITLE = "TSP problems (BruteForce vs ACO)";
    inline sf::Color BACKGROUND_COLOR {30, 30, 45};
    inline std::string BACKGROUND_MUSIC = std::string(MUSICS_DIR) + "/background_music.ogg";
    inline constexpr float bg_music_volume = 100;

    // Town
    inline constexpr float t_radius = 10;
    inline sf::Color t_color{255, 215, 0};

    // Path
    inline sf::Color path_color{210, 210, 210};
    inline sf::Color bestPath_color{39, 174, 96};

    // TextManager
    inline std::string fontPath = std::string(FONTS_DIR) + "/JetBrainsMono.ttf";
    inline constexpr int info_size = 13;
    inline std::string townNumberInfo = "* Towns number : ";
    inline std::string totalPossibilityInfo = "* Total number of possibility : ";
    inline std::string bestDistanceInfo = "* Best Distance : ";
    inline std::string searchInfo ="* Seach : ";
    inline std::string progressInfo ="* Progress (%) :";
};