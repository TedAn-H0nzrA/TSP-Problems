#include "Ant.hpp"
#include "Constants.hpp"

Ant::Ant() :    radius(Constants::antRadius), 
                color(Constants::antColor)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
    shape.setOutlineThickness(Constants::antThicknessLineSize);
    shape.setOutlineColor(Constants::antThicknessColor);
}

void Ant::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Ant::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

std::vector<int> Ant::getCurrentPaht() const {
    return currentPaht;
}