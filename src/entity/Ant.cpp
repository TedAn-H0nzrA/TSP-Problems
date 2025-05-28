#include "Ant.hpp"
#include "Constants.hpp"
#include <cmath>

Ant::Ant() :    radius(Constants::antRadius), 
                color(Constants::antColor)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
}

void Ant::setPosition(const sf::Vector2f& pos) {
    float x = pos.x;
    float y = pos.y;

    shape.setPosition(x, y);
}

void Ant::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ant::addPath(int& path) {
    currentPath.push_back(path);
}

void Ant::clearPath() {
    currentPath.clear();
}

const std::vector<int>& Ant::getCurrentPath() const {
    return currentPath;
}