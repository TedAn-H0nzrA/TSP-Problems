#include <iostream>
#include "Simulation.hpp"

int main() {
    std::cout << "TSP problems (BruteForce vs ACO)\n";
    Simulation simulation;

    try{
        simulation.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Error" << std::endl;
    } 

    return 0;
}