#include "Simulation.hpp"
#include "Constants.hpp"

Simulation::Simulation() : isAddingTown(false)
{
    window.create(Constants::desktop, Constants::TITLE, sf::Style::Default);
}

void Simulation::addTown() {
    if (isAddingTown) {
        Town newTown;
        auto mousePos = sf::Mouse::getPosition(window);
        newTown.setPosition(mousePos.x, mousePos.y);

        towns.push_back(newTown);
    }
}

void Simulation::manageEvent() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        
        // Event key
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case (sf::Keyboard::T) :
                    isAddingTown = !isAddingTown;
                    break;
                
                default:
                    isAddingTown = false;    
            }
        }

        // Event Mouse
        if (event.type = sf::Event::MouseButtonPressed) {
            if (isAddingTown && (event.mouseButton.button == sf::Mouse::Left)) {
                addTown();
            }
        }
    }
}

void Simulation::draw() {
    window.clear(Constants::BACKGROUND_COLOR);
    // Draw entity and else
    // Towns
    for (auto&& town : towns) {
        town.draw(window);
    }
    window.display();
}

void Simulation::run() {
    while (window.isOpen()) {
        manageEvent();
        draw();
    }
}