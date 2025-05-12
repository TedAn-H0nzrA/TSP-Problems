#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Town.hpp"

class Simulation{
    private:
        sf::RenderWindow window;


        std::vector<Town> towns;
        bool isAddingTown;
        void addTown();

        void draw();
        void manageEvent();
    public:
        Simulation();
        
        void run();
};