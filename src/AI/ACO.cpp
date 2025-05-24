#include "ACO.hpp"
#include "Constants.hpp"
#include <cmath>
#include <iostream>
ACO::ACO(std::vector<Town>& towns) :    Q(Constants::ACO_pheromone_depot_intensity),
                                        towns(towns)
{
    // Inialize paramter
    matrixDistance.resize(towns.size(), std::vector<float>(towns.size(), 0.0f));

    // Initialized path index && compute distance matrix
    for (size_t i = 0; i < towns.size(); i++) {
        townsIndex.push_back(static_cast<int>(i));
    }
    computeDistanceMatrix();
}

float ACO::calculateDistance(const sf::Vector2f& a, const sf::Vector2f& b) {
    float dist;

    float dx = a.x - b.x;
    float dy = a.y - b.y;

    dist = std::sqrt((dx * dx) + (dy * dy));

    return dist;
}

float ACO::phermoneQuantity(int indexI, int indexJ, std::vector<int>& pathOfTheAnt_k) {
    bool found = false;

    // Calculate totale distance of the path that the ant walk in
    float Lk = 0;       // Lk or the total distance of the path returning to the begining
    for (size_t i = 0; i < pathOfTheAnt_k.size() - 1; i++) {
        int currentTown = pathOfTheAnt_k[i];
        int nextTown = pathOfTheAnt_k[i + 1];
        Lk += calculateDistance(towns[currentTown].getPosition(), towns[nextTown].getPosition());

        
        // Find if indexI and indexJ is in the path of the ant k
        int a = pathOfTheAnt_k[i];
        int b = pathOfTheAnt_k[i + 1];
        
        if ((a == indexI && b == indexJ) || (a == indexJ && b == indexI)) {
            // indexI and indexJ is in the path
            found = true;
            break;
        }
    }

    // Calcule the distance of returning in the first Town
    Lk += calculateDistance(towns[pathOfTheAnt_k.back()].getPosition(), towns[pathOfTheAnt_k.front()].getPosition());

    if(!found) return 0;
    
    float deltaT = Q / Lk;
    return deltaT;
}


void ACO::computeDistanceMatrix() {
    for (size_t i = 0; i < towns.size(); i++) {
        for (size_t j = 0; j < towns.size(); j++) {
            float dist = calculateDistance(towns[i].getPosition(), towns[j].getPosition());
            matrixDistance[i][j] = dist;
        }
    }

    for (size_t i = 0; i < matrixDistance.size(); i++) {
        for (size_t j = 0; j < matrixDistance.size(); j++) {
            std::cout << matrixDistance[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void ACO::draw(sf::RenderWindow& window) {
    // Drawing ants
    for (auto&& ant : ants) {
        ant.draw(window);
    }
}