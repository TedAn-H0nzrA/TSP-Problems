#include "Simulation.hpp"
#include "Constants.hpp"

Simulation::Simulation() {
    window.create(Constants::desktop, Constants::TITLE, sf::Style::Default);
}

void Simulation::draw() {
    window.clear(Constants::BACKGROUND_COLOR);
    // Draw entity and else
    
    window.display();
}

void Simulation::manageEvent() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
    }
}

void Simulation::run() {
    while (window.isOpen()) {
        manageEvent();
        draw();
    }
}