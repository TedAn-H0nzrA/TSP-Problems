// Town.cpp
// Town property and parameter

#include "Town.hpp"
#include "Constants.hpp"

// Constructor
Town::Town() : radius(Constants::t_radius)
{
    shape.setRadius(radius);
    shape.setFillColor(Constants::t_color);
    shape.setOrigin(radius, radius);
}

// Setting the position of the towns on the screen
void Town::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

// Getters
sf::Vector2f Town::getPosition() const {
    return shape.getPosition();
}

// Drawing town
void Town::draw(sf::RenderWindow& window) {
    window.draw(shape);
}