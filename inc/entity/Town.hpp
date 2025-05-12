#pragma once

#include <SFML/Graphics.hpp>

class Town{
    private:
        sf::CircleShape shape;
        float radius;

    public:
        Town();
        
        void setPosition(float x, float y);
        sf::Vector2f getPosition() const;
        void draw(sf::RenderWindow& window);
};