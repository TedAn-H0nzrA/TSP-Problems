// BruteForce.cpp
// Implementation of the search fonction of BruteForce algorithme

#include "BruteForce.hpp"
#include <iostream>

// Constructor
// Take a vector of Town as parameter and initialize all intern variable
BruteForce::BruteForce(std::vector<Town>& towns) : 
                towns(towns),
                bestDistance(std::numeric_limits<float>::max()),
                finished(false),
                search_finished(0)

{}

// Defined the list of town (reused if towns change)
void BruteForce::setTowns(std::vector<Town>& newTowns) {
    towns = newTowns;
}

// Calculate distance of 2 entities (2D)
// Parameter: Position of 2 entities
// @return distance (float)
float BruteForce::calculDistance(const sf::Vector2f& a, const sf::Vector2f& b) {
    float dist;

    float dx = a.x - b.x;
    float dy = a.y - b.y;

    dist = std::sqrt((dx * dx) + (dy * dy));

    return dist;
}

// Calculate the total distance of a path (towns order)
// Parameter: path (vector index representing towns order)
// @return total distance (float)
float BruteForce::pathLength(const std::vector<int>& path) {
    if (path.size() < 2) return 0;
    float total = 0;

    // Calculate length of one path
    for (size_t i = 0; i < path.size() - 1; i++) {
        total += calculDistance(towns[path[i]].getPosition(), towns[path[i + 1]].getPosition());
    }

    // Path to initial position
    total += calculDistance(towns[path.back()].getPosition(), towns[path[0]].getPosition());

    return total;
}

// Reset value and data for another search
void BruteForce::reset() {
    int numberTowns = towns.size();
    currentPath.resize(numberTowns);
    for (int i = 0; i < numberTowns; i++) currentPath[i] = i;
    bestDistance = std::numeric_limits<float>::max();

    bestPath.clear();
    finished = false;
    std::cout << "[DEBUG] BruteForce reset avec " << numberTowns << " villes\n";
}

// Perform a permutation state et evaluate the currente distance
// Core of BruteForce algorithme
// @return true if the search continue, and false if all the permutation if tested
bool BruteForce::resolveStep() {
    if (finished) return false;

    // Evaluate result
    float dist = pathLength(currentPath);
    search_finished++;
    if (dist < bestDistance) {
        bestDistance = dist;
        bestPath = currentPath;
    }

    // Generate the next Permutation
    if (!std::next_permutation(currentPath.begin(), currentPath.end())) {
        finished = true;
    }

    return !finished;
}

// Getters
std::vector<int> BruteForce::getCurrentPath() const {
    return currentPath;
}
std::vector<int> BruteForce::getBestPath() const {
    return bestPath;
}
float BruteForce::getBestDistance() const {
    return bestDistance;
}
int BruteForce::getSearchFinised() const {
    return search_finished;
}
bool BruteForce::isFinished() const {
    return finished;
}