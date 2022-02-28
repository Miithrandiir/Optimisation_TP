//
// Created by mithrandir on 28/01/2022.
//

#ifndef TP1_SOLUTION_HPP
#define TP1_SOLUTION_HPP


#include <utility>
#include <vector>
#include <iostream>
#include <limits>

class Solution {
public:
    std::vector<bool> taken;
    double z;
    double w;
    double fitness;

    Solution() {
        this->fitness = std::numeric_limits<double>::min();
        z=0.0;
        w=0.0;
    }

    Solution(std::vector<bool> solutions) {taken = solutions;}

    friend std::ostream &operator<<(std::ostream &os, const Solution &solution);

    std::vector<bool> get_taken() { return taken; };

    void set_fitness(double newFitness) { fitness = newFitness; }

    double get_fitness() const { return fitness; }
};


#endif //TP1_SOLUTION_HPP
