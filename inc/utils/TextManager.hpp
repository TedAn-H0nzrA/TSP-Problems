#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class TextManager {
    private:
        sf::Font font;
        sf::Text text;
    
    public:
        TextManager();

        void setString(const std::string& str);
        void setCharacterSize(int size);
        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);
};