// Simulation.hpp
// Initialize project parameter and attribut
// Launch core of the entire projetct (AI, window, etc)


#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <chrono>
#include "Town.hpp"
#include "TextManager.hpp"
#include "BruteForce.hpp"
#include "PathRender.hpp"

// class Simulation, main class of the project
// Manage the entire simulation lifecycle, form visual rendering to entity and AI update
class Simulation{
    private:
        sf::RenderWindow window;                    // Main window

        sf::Music music_background;                 // Music background 
        bool isPlayMusicBG;
        void playBackgroundMusic();

        std::vector<Town> towns;                    // Lists of towns
        bool isAddingTown;                          // True: user can add Town
        std::vector<sf::Vector2f> townPosition;     // List of townPosition
        void addTown();

        TextManager townInfo;                       // Render text: Number of Town
        std::string str_townInfo;                   // The text taking the number of town and description caption
        int townNum;                                // Number of town

        TextManager totalPossibilityInfo;           // Render Text: Number of possibility
        sf::Color totalPossibilityColor;            // Color of the text
        std::string str_totalPossibilityInfo;       // The text taking the number of possibility and caption
        unsigned long long totalPossibilityCalcule; // Number of possibility

        // AI
        TextManager bestDistanceInfo;               // Render text of: the best distance
        std::string str_bestDistanceInfo;           // The text: caption + best distance value
        float bestDistance;                         // Value of the best distance so far

        TextManager searchInfos;                    // Render  text of interation
        std::string str_searchInfo;                 // Value of the iteration + caption
        int search;                                 // Value of the iteration

        TextManager progressInfo;                   // Render Text of: the % of iteration
        std::string str_progressInfo;               // caption + value
        float progress;                             // Value % of the itetation

        // BruteForce
        BruteForce ai_bruteForce;                   // BruteForce algorithme
        bool activate_bruteForce;                   // True: BruteForce resolve


        // Path
        PathRender currentPath;                     // Current path class
        PathRender bestPath;                        // Best path class

        void AI_solve();

        int generateTown_number;
        void generateTown();

        void draw();
        void manageEvent();
        void update();
        void reset();

    public:
        Simulation();
        
        void run();
};