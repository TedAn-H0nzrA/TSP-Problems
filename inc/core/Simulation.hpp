#pragma once

#include <SFML/Graphics.hpp>

class Simulation{
    private:
        sf::RenderWindow window;


        void draw();
        void manageEvent();
    public:
        Simulation();
        
        void run();
};