#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Town.hpp"
#include "TextManager.hpp"

class Simulation{
    private:
        sf::RenderWindow window;

        sf::Music music_background;
        bool isPlayMusicBG;
        void playBackgroundMusic();

        std::vector<Town> towns;
        bool isAddingTown;
        void addTown();

        TextManager townInfo;
        std::string str_townInfo;
        int townNum;

        TextManager totalPossibilityInfo;
        sf::Color totalPossibilityColor;
        std::string str_totalPossibilityInfo;
        std::string srt_totalPossibility;
        double totalPossibilityCalcule;

        void draw();
        void manageEvent();
        void update();

    public:
        Simulation();
        
        void run();
};