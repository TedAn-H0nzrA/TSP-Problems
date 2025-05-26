#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>


class Ant{
    private:
        sf::CircleShape shape;
        float radius;
        sf::Color color;
        std::vector<int> currentPath;

    public:
        Ant();

        void setPosition(const sf::Vector2f& pos);
        void draw(sf::RenderWindow& window);

        void addPath(int& path);
        void clearPath();

        const std::vector<int>& getCurrentPath() const;
};