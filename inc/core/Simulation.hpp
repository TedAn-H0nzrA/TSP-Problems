#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Town.hpp"
#include "TextManager.hpp"
#include "BruteForce.hpp"
#include "PathRender.hpp"

class Simulation{
    private:
        sf::RenderWindow window;

        sf::Music music_background;
        bool isPlayMusicBG;
        void playBackgroundMusic();

        std::vector<Town> towns;
        bool isAddingTown;
        std::vector<sf::Vector2f> townPosition;
        void addTown();

        TextManager townInfo;
        std::string str_townInfo;
        int townNum;

        TextManager totalPossibilityInfo;
        sf::Color totalPossibilityColor;
        std::string str_totalPossibilityInfo;
        std::string srt_totalPossibility;
        double totalPossibilityCalcule;

        // AI
        BruteForce ai_bruteForce;
        bool activate_bruteForce;

        // Path
        PathRender currentPath;
        PathRender bestPath;

        void AI_solve();

        void draw();
        void manageEvent();
        void update();

    public:
        Simulation();
        
        void run();
};