#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>


class Ant{
    private:
        sf::CircleShape shape;
        float radius;
        sf::Color color;
        std::vector<int> currentPaht;

    public:
        Ant();

        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);

        std::vector<int> getCurrentPaht() const;
};