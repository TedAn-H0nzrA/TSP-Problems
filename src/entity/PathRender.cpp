// PathRender.cpp
// Rendering lines of visualization and fonctionality

#include "PathRender.hpp"
#include "Constants.hpp"
#include <iostream>

// Constructor and initializor
PathRender::PathRender():   lines(sf::LinesStrip),
                            linesColor(Constants::path_color)
{}

// Giving the line a specific color
void PathRender::setLineColor(const sf::Color& newColor) {
    linesColor = newColor;
}

// Setting the path base on the position of all the towns
// @param: list of position and index of the position in order
void PathRender::setPath(const std::vector<sf::Vector2f>& position, const std::vector<int>& path) {
    // std::cout << "[DEBUG] setPath called with " << path.size() << " points.\n";
    if (path.empty() || position.empty()) return;
    lines.clear();
    lines.setPrimitiveType(sf::LinesStrip);

    for (auto&& index : path) {
        lines.append(sf::Vertex(position[index], linesColor));
    }
    // Return to initial position
    lines.append(sf::Vertex(position[path[0]], linesColor));
}

// Reset path and clean it
void PathRender::clear() {
    lines.clear();
}

// Drawing the lines
void PathRender::draw(sf::RenderWindow& window) {
    window.draw(lines);
}