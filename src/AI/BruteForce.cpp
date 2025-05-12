#include "BruteForce.hpp"
#include <iostream>

BruteForce::BruteForce(std::vector<Town>& towns) : 
                towns(towns),
                bestDistance(std::numeric_limits<float>::max()),
                finished(false)

{}

void BruteForce::setTowns(std::vector<Town>& newTowns) {
    towns = newTowns;
}

float BruteForce::calculDistance(const sf::Vector2f& a, const sf::Vector2f& b) {
    float dist;

    float dx = a.x - b.x;
    float dy = a.y - b.y;

    dist = std::sqrt((dx * dx) + (dy * dy));

    return dist;
}

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

void BruteForce::reset() {
    int numberTowns = towns.size();
    currentPath.resize(numberTowns);
    for (int i = 0; i < numberTowns; i++) currentPath[i] = i;
    bestDistance = std::numeric_limits<float>::max();

    bestPath.clear();
    finished = false;
    std::cout << "[DEBUG] BruteForce reset avec " << numberTowns << " villes\n";
}

bool BruteForce::resolveStep() {
    if (finished) return false;

    // Evaluate result
    float dist = pathLength(currentPath);
    if (dist < bestDistance) {
        bestDistance = dist;
        bestPath = currentPath;
    }

    // Change permutation
    if (!std::next_permutation(currentPath.begin(), currentPath.end())) {
        finished = true;
    }

    return !finished;
}

std::vector<int> BruteForce::getCurrentPath() const {
    return currentPath;
}
std::vector<int> BruteForce::getBestPath() const {
    return bestPath;
}
float BruteForce::getBestDistance() const {
    return bestDistance;
}
bool BruteForce::isFinished() const {
    return finished;
}