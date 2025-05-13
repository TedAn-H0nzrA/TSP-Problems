// PathRender.hpp
// Visualization of the path when the AI works

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

// Class PahthRender
class PathRender{
    private:
        sf::VertexArray lines;      // Lines (actually a list because of the path)
        sf::Color linesColor;       // Lines Color

    public:
        PathRender();
        void setLineColor(const sf::Color& newColor);

        void setPath(const std::vector<sf::Vector2f>& position, const std::vector<int>& path);
        void clear();

        void draw(sf::RenderWindow& window);
};