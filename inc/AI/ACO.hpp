// ACO.hpp
// Header of the ACO Algorithme
// Declare the ACO class, including all the parameters, attributes (public and private)

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "Town.hpp"
#include "Ant.hpp"

class ACO{
    private:   
        std::vector<Town> towns;                            // Lists of towns
        std::vector<std::vector<float>> matrixDistance;     // Matrix nxn for distance between town
        std::vector<std::vector<float>> matrixPheromone;    // Matrix nxn for pheromone in path
        std::vector<int> townsIndex;                        // towns index
        std::vector<Ant> ants;                              // Lists of Ants
        int totalNumber_ants;

        float Q;                                            // Intensity of pheromone deposition
        float rho;                                          // Abstract evaporation rate
        float alpha;                                        // Pheromone influence
        float beta;                                         // Distance influence   
        
        // Random parameters
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<int> distIndex;
        std::uniform_real_distribution<float> distRouletteWheel;
        void randomIndex();

        float pheromoneDelta(int indexI, int indexJ, const std::vector<int>& pathOfTheAnt);
        float evaporatePheromone(int indexI, int indexJ);
        void updatePheromoneMatrix();

        // Core of the ACO
        std::vector<float> calculeMoveProbabilities(Ant& ant);
        int rouletteWheel(const std::vector<float>& probabilities);

        float calculateDistance(const sf::Vector2f& a, const sf::Vector2f& b);
        void computeDistanceMatrix();

        
        public:
        ACO(std::vector<Town>& towns);
        void runIteration();
        
        void draw(sf::RenderWindow& window);
};