// TextManager.hpp
// Making the management of text and render

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

// class TextManager organizing the operation
class TextManager {
    private:
        sf::Font font;      // Font for the text
        sf::Text text;      // Text to manipulate
    
    public:
        TextManager();

        void setString(const std::string& str);
        void setCharacterSize(int size);
        void setPosition(float x, float y);
        void setFillColor(sf::Color& textColor);
        
        void draw(sf::RenderWindow& window);
};