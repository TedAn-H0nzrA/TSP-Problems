#include "ACO.hpp"
#include "Constants.hpp"
#include <cmath>
#include <iostream>
ACO::ACO(std::vector<Town>& towns) :    Q(Constants::pheromone_deposit_intensity),
                                        towns(towns),
                                        alpha(Constants::alpha_importanceOf_pheromones),
                                        beta(Constants::beta_importanceOf_heuristicAttractivness),
                                        rho(Constants::evaporation_rate),
                                        totalNumber_ants(Constants::totalNumber_ants)
{
    // Inialize paramter
    matrixDistance.resize(towns.size(), std::vector<float>(towns.size(), 0.0f));
    matrixPheromone.resize(towns.size(), std::vector<float>(towns.size(), Constants::initiale_evaporation_rate));
    
    // Intialize ants
    for (size_t i = 0; i < totalNumber_ants; i++) {
        Ant ant;
        ants.push_back(ant);
    }

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

float ACO::pheromoneDelta(int indexI, int indexJ, std::vector<int>& pathOfTheAnt_k) {
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

float ACO::evaporatePheromone(int indexI, int indexJ) {
    float updatePheromone;
    float currentQuantity = matrixPheromone[indexI][indexJ];
    float contributionOfAllAnts = 0;        // Contribution of all the ant in I and J

    for (auto&& ant : ants) {
        std::vector<int> pathOfTheAnt_k = ant.getCurrentPaht();
        for (size_t i = 0; i < pathOfTheAnt_k.size() - 1; i++) {
            int currentIndex = i;
            int nextIndex = i + 1;

            if ((currentIndex == indexI && nextIndex == indexJ) ||
                (currentIndex == indexJ && nextIndex == indexI)) {
                contributionOfAllAnts += pheromoneDelta(indexI, indexJ, pathOfTheAnt_k);
            }
        }
    }

    updatePheromone = (1 - rho) * currentQuantity + contributionOfAllAnts;
    
    return updatePheromone;   
}

void ACO::updatePheromoneMatrix() {
    for (size_t i = 0; i < towns.size(); i++) {
        for (size_t j = 0; j < towns.size(); j++) {
            matrixPheromone[i][j] = evaporatePheromone(i, i);
        }
    }
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