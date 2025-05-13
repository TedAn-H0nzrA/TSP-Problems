// BruteForce.hpp
// Initialize class parameter and attribute
// Artificial Intelligence based on BruteForce algorithme

#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <limits>
#include "Town.hpp"
#include "PathRender.hpp"


/// class BruteForce
/// Implementation of an AI based on the comprehensive TSP approach
class BruteForce{
    private:
        std::vector<Town> towns;        // Town list

        float bestDistance;             // Best Distance find 
        std::vector<int> bestPath;      // Best path tested and find
        std::vector<int> currentPath;   // Current path tested
        bool finished;                  // True if all the permutation is tested
        int search_finished;            // Total number of iteration

        float calculDistance(const sf::Vector2f& a, const sf::Vector2f& b);
        float pathLength(const std::vector<int>& path);

    public:
        BruteForce(std::vector<Town>& towns);
        void setTowns (std::vector<Town>& towns);

        void reset();
        bool resolveStep();

        // Getters
        std::vector<int> getCurrentPath() const;
        std::vector<int> getBestPath() const;
        float getBestDistance() const;
        int getSearchFinised() const;
        bool isFinished() const;
};