// Simulation.cpp
// Implementation of all Simulation class functions and attributes

#include "Simulation.hpp"
#include "Constants.hpp"
#include "LoadRessource.hpp"
#include <iostream>
#include <iomanip>
#include <random>

// Constructor and Initialize default value
Simulation::Simulation() :  isAddingTown(false),
                            isPlayMusicBG(false),
                            townNum(0),
                            generateTown_number(Constants::generateTown_number),
                            totalPossibilityCalcule(0),
                            ai_bruteForce(towns),
                            activate_bruteForce(false),
                            activate_ACO(false),
                            bestDistance(0),
                            search(0),
                            progress(0)
{
    window.create(Constants::desktop, Constants::TITLE, sf::Style::Default);

    // Load background music
    if (LoadRessource::loadMusic(Constants::BACKGROUND_MUSIC, music_background)) isPlayMusicBG = true;

    // ===Text manage===
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

    // AI info
    // *Distance
    bestDistanceInfo.setPosition(10, 90);
    bestDistanceInfo.setCharacterSize(Constants::info_size);
    str_bestDistanceInfo = Constants::bestDistanceInfo + std::to_string(bestDistance);
    bestDistanceInfo.setString(str_bestDistanceInfo);

    // *Search
    searchInfos.setPosition(10, 50);
    searchInfos.setCharacterSize(Constants::info_size);
    str_searchInfo = Constants::searchInfo + std::to_string(search);
    searchInfos.setString(str_searchInfo);

    // *Progress
    progressInfo.setPosition(10, 70);
    progressInfo.setCharacterSize(Constants::info_size);
    str_progressInfo = Constants::progressInfo + std::to_string(progress);
    progressInfo.setString(str_progressInfo);

    // *Mode
    modeInfo.setPosition(10, 110);
    modeInfo.setCharacterSize(Constants::info_size);
    modeInfo_option[0] = "No active mode";
    modeInfo_option[1] = "Add Towns";
    modeInfo_option[2] = "BruteForce algorithme";
    modeInfo_option[3] = "ACO algorithme";
    str_modeInfos = Constants::modeInfo + modeInfo_option[0];
    modeInfo.setString(str_modeInfos);

    // ===Path===
    currentPath.setLineColor(Constants::path_color);
    bestPath.setLineColor(Constants::bestPath_color);

}

// Manage the background music (Play/Pause)
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

// Manage all of the event in the simulation
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
                    std::cout << "T pressed, isAddingTown = " << isAddingTown << std::endl;
                    break;
                
                case (sf::Keyboard::B) :
                    isAddingTown = false;
                    activate_bruteForce = true;
                    ai_bruteForce.setTowns(towns);
                    ai_bruteForce.reset(); // Reset après avoir ajouter des villes
                    AI_solve();
                    break;

                case (sf::Keyboard::G) :
                    if (!activate_bruteForce) {
                        isAddingTown = !isAddingTown;
                        generateTown();
                    } 
                    break;

                case (sf::Keyboard::Space) :
                    reset();
                    break;

                default:
                    isAddingTown = false;
                    break;
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

// Side Fonction for calculating the factorial
unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}


// Allow to add town by pressing the mousButton::Left once
// Based on isAddingTown = true
void Simulation::addTown() {
    Town newTown;
    auto mousePos = sf::Mouse::getPosition(window);
    newTown.setPosition(mousePos.x, mousePos.y);

    towns.push_back(newTown);
    townNum = towns.size();
    totalPossibilityCalcule = factorial(townNum - 1) / 2;
    
    // Town Position
    townPosition.push_back(newTown.getPosition());
}

// Let the AI sole the probleme of TSP
// 2 AI: BruteForce && ACO
void Simulation::AI_solve() {
    if (activate_bruteForce) {
        if (!ai_bruteForce.isFinished()) {
            ai_bruteForce.resolveStep();
            currentPath.setPath(townPosition, ai_bruteForce.getCurrentPath());
            bestPath.setPath(townPosition, ai_bruteForce.getBestPath());
            bestDistance = ai_bruteForce.getBestDistance();
            search = ai_bruteForce.getSearchFinised();
            // std::cout << "[DEBUG] Current path size: " << ai_bruteForce.getCurrentPath().size() << "\n";
            // std::cout << "[DEBUG] Best path size: " << ai_bruteForce.getBestPath().size() << "\n";
        }
    } else if (activate_ACO) {
        // TODO : Add ACO resolution step here
    }
}

void Simulation::generateTown() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distX(Constants::t_radius, Constants::WIDTH - Constants::t_radius);
    std::uniform_real_distribution<float> distY(Constants::t_radius, Constants::HEIGHT - Constants::t_radius);

    for (size_t i = 0; i < generateTown_number; i++) {
        Town newTown;
        newTown.setPosition(distX(gen), distY(gen));

        towns.push_back(newTown);
        
        // Town Position
        townPosition.push_back(newTown.getPosition());
    }
    townNum = towns.size();
    totalPossibilityCalcule = factorial(townNum - 1) / 2;
}

// Fonction to draw everything in sync
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
    bestDistanceInfo.draw(window);
    searchInfos.draw(window);
    progressInfo.draw(window);
    modeInfo.draw(window);

    // AI
    // Path
    currentPath.draw(window);
    bestPath.draw(window);

    window.display();
}

void Simulation::update_ModeInfo() {
    std::string modeNow;
    
    if (isAddingTown) {
        modeNow = modeInfo_option[1];
    } else if (activate_bruteForce) {
        modeNow = modeInfo_option[2];
    } else if (activate_ACO) {
        modeNow = modeInfo_option[3];
    } else {
        modeNow = modeInfo_option[0];
    }


    if (modeNow == modeInfo_option[3]) {
        modeInfo.setFillColor(Constants::defauleMode);
    } else {
        modeInfo.setFillColor(Constants::activeMode);
    }

    str_modeInfos = Constants::modeInfo + modeNow;
    modeInfo.setString(str_modeInfos);
}

// Fonction ot update calcule, text, color, ai 
void Simulation::update() {
    // Update Text
    str_townInfo = Constants::townNumberInfo + std::to_string(townNum);
    townInfo.setString(str_townInfo);

    if (townNum <= 3) {
        totalPossibilityColor = sf::Color(46, 204, 113);
    } else if (townNum <= 5) {
        totalPossibilityColor = sf::Color(39, 174, 96);
    } else if (townNum <= 7) {
        totalPossibilityColor = sf::Color(241, 196, 15);
    } else if (townNum <= 9) {
        totalPossibilityColor = sf::Color(230, 126, 34);
    } else {
        totalPossibilityColor = sf::Color(231, 76, 60);
    }

    // If the number of town is more than 66, render Too big
    if (townNum >= 66) {
        str_totalPossibilityInfo = Constants::totalPossibilityInfo + std::string("Too Big to calculate");
    } else {
        str_totalPossibilityInfo = Constants::totalPossibilityInfo + std::to_string(totalPossibilityCalcule);
    }
    totalPossibilityInfo.setString(str_totalPossibilityInfo);
    totalPossibilityInfo.setFillColor(totalPossibilityColor);

    AI_solve();
    str_bestDistanceInfo = Constants::bestDistanceInfo + std::to_string(bestDistance);
    bestDistanceInfo.setString(str_bestDistanceInfo);

    str_searchInfo = Constants::searchInfo + std::to_string(search);
    searchInfos.setString(str_searchInfo);

    progress = static_cast<float>(search) / static_cast<float>(totalPossibilityCalcule) * 100.f;
    str_progressInfo = Constants::progressInfo + std::to_string(progress);
    progressInfo.setString(str_progressInfo);

    update_ModeInfo();
}

// Reset the simulation to his default parameter and value (AI include)
void Simulation::reset() {
    // Reset AI
    ai_bruteForce.reset();
    ai_bruteForce = BruteForce(towns);
    activate_bruteForce = false;
    
    // Reset Town
    isAddingTown = false;
    townNum = 0;
    townPosition.clear();

    // Reset calcule data
    totalPossibilityCalcule = 0;
    progress = 0;
    search = 0;

    // Reset path Data
    bestDistance = 0;
    bestPath.clear();
    currentPath.clear();
    towns.clear();
}

// Allow to run simulation
// Only function public to call
void Simulation::run() {
    while (window.isOpen()) {
        manageEvent();
        update();
        draw();
    }
}