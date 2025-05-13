// Town.hpp
// Towns property and form visualization

#pragma once

#include <SFML/Graphics.hpp>

// Class Town for shape, position, and drawing
class Town{
    private:
        sf::CircleShape shape;      // Shape of the town representing by circle
        float radius;               // Radius of the circle shape

    public:
        Town();
        
        void setPosition(float x, float y);
        sf::Vector2f getPosition() const;
        void draw(sf::RenderWindow& window);
};