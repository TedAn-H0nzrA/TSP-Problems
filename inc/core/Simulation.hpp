#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Town.hpp"

class Simulation{
    private:
        sf::RenderWindow window;

        sf::Music music_background;
        bool isPlayMusicBG;
        void playBackgroundMusic();

        std::vector<Town> towns;
        bool isAddingTown;
        void addTown();

        void draw();
        void manageEvent();
    public:
        Simulation();
        
        void run();
};