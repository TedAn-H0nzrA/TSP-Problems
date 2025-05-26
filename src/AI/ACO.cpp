#include "ACO.hpp"
#include "Constants.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
ACO::ACO(std::vector<Town>& towns) :    gen(rd()),
                                        Q(Constants::pheromone_deposit_intensity),
                                        towns(towns),
                                        alpha(Constants::alpha_importanceOf_pheromones),
                                        beta(Constants::beta_importanceOf_heuristicAttractivness),
                                        rho(Constants::evaporation_rate),
                                        totalNumber_ants(Constants::totalNumber_ants)
{
    // Initialize parameters
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

    // Initialize random paramaters
    distIndex = std::uniform_int_distribution<int> (0, townsIndex.size() - 1);
    distRouletteWheel = std::uniform_real_distribution<float> (0, 1);
}

void ACO::randomIndex() {
    for (auto&& ant :ants) {
        int startTown = distIndex(gen);
        ant.addPath(startTown);
    }
}

float ACO::calculateDistance(const sf::Vector2f& a, const sf::Vector2f& b) {
    float dist;

    float dx = a.x - b.x;
    float dy = a.y - b.y;

    dist = std::sqrt((dx * dx) + (dy * dy));

    return dist;
}

float ACO::pheromoneDelta(int indexI, int indexJ, const std::vector<int>& pathOfTheAnt_k) {
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

    // Calcule the return distance
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
        std::vector<int> pathOfTheAnt_k = ant.getCurrentPath();
        for (size_t i = 0; i < pathOfTheAnt_k.size() - 1; i++) {
            int currentIndex = pathOfTheAnt_k[i];
            int nextIndex = pathOfTheAnt_k[i + 1];

            if ((currentIndex == indexI && nextIndex == indexJ) ||
                (currentIndex == indexJ && nextIndex == indexI)) {
                contributionOfAllAnts += pheromoneDelta(indexI, indexJ, pathOfTheAnt_k);
            }
        }
    }

    updatePheromone = (1 - rho) * currentQuantity + contributionOfAllAnts;
    
    return updatePheromone;   
}

std::vector<float> ACO::calculeMoveProbabilities(Ant& ant) {
    std::vector<int> currentPath = ant.getCurrentPath();
    int currentTown = currentPath.back();

    std::vector<float> probabilities(towns.size(), 0);

    // Calculate denominator
    float denominator = 0;

    for (size_t nextTown = 0; nextTown < towns.size(); nextTown++) {
        // Skip already visited town to ensure each ant visite each vity exactly once
        if (std::find(currentPath.begin(), currentPath.end(), nextTown) != currentPath.end()) continue;

        float tou_ij = matrixPheromone[currentTown][nextTown];
        float eta_ij = 1 / matrixDistance[currentTown][nextTown];

        denominator += pow(tou_ij, alpha) * pow(eta_ij, beta);
    }

    // Calculate probabilies for each town
    for (size_t nextTown = 0; nextTown < towns.size(); nextTown++) {
        if (std::find(currentPath.begin(), currentPath.end(), nextTown) != currentPath.end()) continue;

        float tou_ij = matrixPheromone[currentTown][nextTown];
        float et_ij = 1 / matrixDistance[currentTown][nextTown];

        float numerator = pow(tou_ij, alpha) * pow(et_ij, beta);
        probabilities[nextTown] = numerator / denominator;
    }


    return probabilities;
}

int ACO::rouletteWheel(const std::vector<float>& probabilities) {
    std::vector<float> cumulative_interval(probabilities.size(), 0);

    // Cumulative interval
    cumulative_interval[0] = probabilities[0];
    for (size_t i = 1; i < probabilities.size(); i++) {
        float cumInter = cumulative_interval[i - 1] + probabilities[i];
        cumulative_interval[i] = cumInter;
    }

    // Rouellete whelle selection by random number
    float rw_selection = distRouletteWheel(gen);

    for (size_t i = 0; i < cumulative_interval.size(); i++) {
        if (rw_selection <= cumulative_interval[i]) {
            return static_cast<int>(i);
        }
    }

    // Safety return 
    return static_cast<int>(probabilities.size() - 1);
}

void ACO::updatePheromoneMatrix() {
    for (size_t i = 0; i < towns.size(); i++) {
        for (size_t j = 0; j < towns.size(); j++) {
            matrixPheromone[i][j] = evaporatePheromone(i, j);
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

void ACO::runIteration() {
    for (auto&& ant : ants) {
        // Start position of each ant
        ant.clearPath();
        int startTown = distIndex(gen);
        ant.addPath(startTown);
        ant.setPosition(towns[startTown].getPosition());

        while (ant.getCurrentPath().size() < towns.size()) {
            auto probs = calculeMoveProbabilities(ant);
            int nextTown = rouletteWheel(probs);
            ant.addPath(nextTown);
            ant.setPosition(towns[nextTown].getPosition());
        }
    }

    updatePheromoneMatrix();
}

void ACO::draw(sf::RenderWindow& window) {
    // Drawing ants
    for (auto&& ant : ants) {
        ant.draw(window);
    }
}