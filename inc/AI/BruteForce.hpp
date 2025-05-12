#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <limits>
#include "Town.hpp"
#include "PathRender.hpp"

class BruteForce{
    private:
        std::vector<Town> towns;

        float bestDistance;
        std::vector<int> bestPath;
        std::vector<int> currentPath;
        bool finished;

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
        bool isFinished() const;
};