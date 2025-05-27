// BruteForce.cpp
// Implementation of the search fonction of BruteForce algorithme

#include "BruteForce.hpp"
#include <iostream>
#include <algorithm>

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

    // Intitialize the first town manualy
    // Fixed towns 1 => (n-1)!
    currentPath.resize(numberTowns);
    currentPath[0] = 0;
    for (int i = 1; i < numberTowns; i++) currentPath[i] = i;
    std::sort(currentPath.begin() + 1, currentPath.end());
    bestDistance = std::numeric_limits<float>::max();

    bestPath.clear();
    finished = false;
    search_finished = 0;
    std::cout << "[DEBUG] BruteForce reset avec " << numberTowns << " villes\n";
}

// Perform a permutation state et evaluate the currente distance
// Core of BruteForce algorithme
// @return true if the search continue, and false if all the permutation if tested
bool BruteForce::resolveStep() {
    if (finished) return false;
    std::vector<int> reversedPath = currentPath;
    std::reverse(reversedPath.begin() + 1, reversedPath.end());

    // Evaluate result
    if (currentPath < reversedPath) {
        float dist = pathLength(currentPath);
        search_finished++;
        if (dist < bestDistance) {
            bestDistance = dist;
            bestPath = currentPath;
        }
    }

    // Generate the next Permutation only of 1 to (n-1)
    if (!std::next_permutation(currentPath.begin() + 1, currentPath.end())) {
        finished = true;
    }

    return !finished;
}

// Getters
const std::vector<int> BruteForce::getCurrentPath() const {
    return currentPath;
}
const std::vector<int> BruteForce::getBestPath() const {
    return bestPath;
}
const float BruteForce::getBestDistance() const {
    return bestDistance;
}
const int BruteForce::getSearchFinised() const {
    return search_finished;
}
const bool BruteForce::isFinished() const {
    return finished;
}