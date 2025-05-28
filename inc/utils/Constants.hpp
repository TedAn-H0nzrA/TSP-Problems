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
    inline constexpr int generateTown_number = 50;

    // Path
    inline sf::Color path_color{220, 220, 220};
    inline sf::Color bestPath_color{39, 174, 96};

    // TextManager
    inline std::string fontPath = std::string(FONTS_DIR) + "/JetBrainsMono.ttf";
    inline constexpr int info_size = 13;
    inline std::string townNumberInfo = "* Towns number : ";
    inline std::string totalPossibilityInfo = "* Total number of possibility : ";
    inline std::string bestDistanceInfo = "* Best Distance : ";
    inline std::string modeInfo = "* Mode : ";
    // BruteForce algorithme
    inline std::string searchInfo = "* Seach : ";
    inline std::string progressInfo = "* Progress (%) :";
    // ACO algorithme
    inline std::string itetationInfo = "* Iteration : ";
    // Color
    inline sf::Color defaultMode{245, 236, 206};
    inline sf::Color activeMode{174, 214, 241};

    // Ant
    inline sf::Color antColor{255, 50, 50};
    inline sf::Color antThicknessColor = sf::Color::Black;
    inline constexpr float antRadius = t_radius - (t_radius / 10);

    // ACO Parameter and constants
    inline constexpr int iteration = 100;
    inline constexpr int totalNumber_ants = 20;
    inline constexpr float pheromone_deposit_intensity = 1;
    inline constexpr float alpha_importanceOf_pheromones = 2;
    inline constexpr float beta_importanceOf_heuristicAttractivness = 1;
    inline constexpr float evaporation_rate = 0.1; // 10% of ρ
    inline constexpr float initiale_evaporation_rate = 1;

    // Phéromone color
    inline const sf::Color ACO_COLOR_HIGH_PHEROMONE = sf::Color(255, 255, 255);
    inline const sf::Color ACO_COLOR_MEDIUM_PHEROMONE = sf::Color(160, 160, 160);
    inline const sf::Color ACO_COLOR_LOW_PHEROMONE = sf::Color(80, 80, 80);
    inline const sf::Color ACO_COLOR_NO_PHEROMONE = sf::Color(30, 30, 30);
    inline const sf::Color ACO_COLOR_CURRENT_PATH = sf::Color(220, 220, 220);
};