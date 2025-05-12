#include "Town.hpp"
#include "Constants.hpp"

Town::Town() : radius(Constants::t_radius)
{
    shape.setRadius(radius);
    shape.setFillColor(Constants::t_color);
    shape.setOrigin(radius, radius);
}

void Town::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

sf::Vector2f Town::getPosition() const {
    return shape.getPosition();
}

void Town::draw(sf::RenderWindow& window) {
    window.draw(shape);
}