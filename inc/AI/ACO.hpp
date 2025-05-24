// ACO.hpp
// Header of the ACO Algorithme
// Declare the ACO class, including all the parameters, attributes (public and private)

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Town.hpp"
#include "Ant.hpp"

class ACO{
    private:   
        std::vector<Town> towns;                            // Lists of towns
        std::vector<std::vector<float>> matrixDistance;     // Matrix nxn for distance between town
        std::vector<std::vector<float>> matrixPheromone;    // Matrix nxn for pheromone in path
        std::vector<int> townsIndex;                        // towns index
        std::vector<Ant> ants;                              // Lists of Ants

        float Q;                                            // Intensity of pheromone deposition
        float phermoneQuantity(int indexI, int indexJ, std::vector<int>& pathOfTheAnt);

        float calculateDistance(const sf::Vector2f& a, const sf::Vector2f& b);
        void computeDistanceMatrix();

    public:
        ACO(std::vector<Town>& towns);
        void draw(sf::RenderWindow& window);
};