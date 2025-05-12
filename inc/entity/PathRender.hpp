#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class PathRender{
    private:
        sf::VertexArray lines;
        sf::Color linesColor;   

    public:
        PathRender();
        void setLineColor(const sf::Color& newColor);

        void setPath(const std::vector<sf::Vector2f>& position, const std::vector<int>& path);
        void clear();

        void draw(sf::RenderWindow& window);
};