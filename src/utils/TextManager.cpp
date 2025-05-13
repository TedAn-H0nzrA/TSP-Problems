// TextManager.cpp
// Parameter of the text rendering

#include "TextManager.hpp"
#include "LoadRessource.hpp"
#include "Constants.hpp"

// Constructor
TextManager::TextManager() {
    font = LoadRessource::loadFont(Constants::fontPath);
    text.setFont(font);
}

// Setting string for render in the window
void TextManager::setString(const std::string& str) {
    text.setString(str);
}

// Setting the size of the charactere (personalizing)
void TextManager::setCharacterSize(int size = Constants::info_size) {
    text.setCharacterSize(size);
}

// Setting position
void TextManager::setPosition(float x, float y) {
    text.setPosition(x, y);
}

// Setting color
void TextManager::setFillColor(sf::Color& textColor) {
    text.setFillColor(textColor);
}

// Draw the text
void TextManager::draw(sf::RenderWindow& window) {
    window.draw(text);
}