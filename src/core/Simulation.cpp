#include "Simulation.hpp"
#include "Constants.hpp"
#include "LoadRessource.hpp"

Simulation::Simulation() :  isAddingTown(false),
                            isPlayMusicBG(false),
                            townNum(0),
                            totalPossibilityCalcule(0)
{
    window.create(Constants::desktop, Constants::TITLE, sf::Style::Default);

    // Load background music
    if (LoadRessource::loadMusic(Constants::BACKGROUND_MUSIC, music_background)) isPlayMusicBG = true;

    // Text manage
    // Town
    townInfo.setPosition(10, 10);
    townInfo.setCharacterSize(Constants::info_size);
    str_townInfo = Constants::townNumberInfo + std::to_string(townNum);
    townInfo.setString(str_townInfo);

    // Iteration
    totalPossibilityInfo.setPosition(10, 30);
    totalPossibilityInfo.setCharacterSize(Constants::info_size);
    str_totalPossibilityInfo = Constants::totalPossibilityInfo + std::to_string(totalPossibilityCalcule);
    totalPossibilityInfo.setString(str_totalPossibilityInfo);

}

void Simulation::playBackgroundMusic() {
    if (isPlayMusicBG) {
        if (music_background.getStatus() != sf::Music::Playing) {
            music_background.setLoop(true);
            music_background.setVolume(Constants::bg_music_volume);
            music_background.play();
        }
    } else {
        if (music_background.getStatus() == sf::Music::Playing) {
            music_background.pause();
        }
    }
}

void Simulation::manageEvent() {
    sf::Event event;
    
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        
        // Event key
        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case (sf::Keyboard::M) :
                    isPlayMusicBG = !isPlayMusicBG;
                    break;

                case (sf::Keyboard::T) :
                    isAddingTown = !isAddingTown;
                    break;
                
                default:
                    isAddingTown = false;    
            }
        }
        
        // Event Mouse
        if (event.type == sf::Event::MouseButtonPressed) {
            if (isAddingTown && (event.mouseButton.button == sf::Mouse::Left)) {
                addTown();
            }
        }

        // Music
        playBackgroundMusic();
    }
}

// Fonction pour calculer la factorielle
unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}


void Simulation::addTown() {
    if (isAddingTown) {
        Town newTown;
        auto mousePos = sf::Mouse::getPosition(window);
        newTown.setPosition(mousePos.x, mousePos.y);

        towns.push_back(newTown);
        townNum = towns.size();
        totalPossibilityCalcule = factorial(townNum);
    }
}

void Simulation::draw() {
    window.clear(Constants::BACKGROUND_COLOR);
    // Draw entity and else
    // Towns
    for (auto&& town : towns) {
        town.draw(window);
    }

    // Text
    townInfo.draw(window);
    totalPossibilityInfo.draw(window);

    window.display();
}

void Simulation::update() {
    str_townInfo = Constants::townNumberInfo + std::to_string(townNum);
    townInfo.setString(str_townInfo);

    str_totalPossibilityInfo = Constants::totalPossibilityInfo + std::to_string(totalPossibilityCalcule);
    totalPossibilityInfo.setString(str_totalPossibilityInfo);
}

void Simulation::run() {
    while (window.isOpen()) {
        manageEvent();
        update();
        draw();
    }
}