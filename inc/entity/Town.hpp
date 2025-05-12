#pragma once

#include <SFML/Graphics.hpp>

class Town{
    private:
        sf::CircleShape shape;
        float radius;

    public:
        Town();
        
        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);
};