#include "TextManager.hpp"
#include "LoadRessource.hpp"
#include "Constants.hpp"

TextManager::TextManager() {
    font = LoadRessource::loadFont(Constants::fontPath);
    text.setFont(font);
}

void TextManager::setString(const std::string& str) {
    text.setString(str);
}

void TextManager::setCharacterSize(int size = Constants::info_size) {
    text.setCharacterSize(size);
}

void TextManager::setPosition(float x, float y) {
    text.setPosition(x, y);
}

void TextManager::setFillColor(sf::Color& textColor) {
    text.setFillColor(textColor);
}

void TextManager::draw(sf::RenderWindow& window) {
    window.draw(text);
}