#include "PathRender.hpp"
#include "Constants.hpp"
#include <iostream>

PathRender::PathRender():   lines(sf::LinesStrip),
                            linesColor(Constants::path_color)
{}

void PathRender::setLineColor(const sf::Color& newColor) {
    linesColor = newColor;
}

void PathRender::setPath(const std::vector<sf::Vector2f>& position, const std::vector<int>& path) {
    std::cout << "[DEBUG] setPath called with " << path.size() << " points.\n";
    if (path.empty() || position.empty()) return;
    lines.clear();
    lines.setPrimitiveType(sf::LinesStrip);

    for (auto&& index : path) {
        lines.append(sf::Vertex(position[index], linesColor));
    }
    // Return to initial position
    lines.append(sf::Vertex(position[0], linesColor));
    
    std::cout << "Lines color: ("
          << static_cast<int>(linesColor.r) << ", "
          << static_cast<int>(linesColor.g) << ", "
          << static_cast<int>(linesColor.b) << ", "
          << static_cast<int>(linesColor.a) << ")"
          << std::endl;

}

void PathRender::clear() {
    lines.clear();
}

void PathRender::draw(sf::RenderWindow& window) {
    window.draw(lines);
}