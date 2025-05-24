#pragma once 

#include <SFML/Graphics.hpp>


class Ant{
    private:
        sf::CircleShape shape;
        float radius;
        sf::Color color;

    public:
        Ant();

        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);
};