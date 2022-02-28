//
// Created by mithrandir on 28/01/2022.
//

#include <random>
#include "RandomSearch.hpp"

Solution RandomSearch::search(int cycle, Knapsack &knapsack) {
    Solution solution;

    Solution tmp_solution;
    solution.taken.resize(knapsack.items.size());
    tmp_solution.taken.resize(knapsack.items.size());
    for (int n = 0; n < cycle; ++n) {

        for (int i = 0; i < knapsack.items.size(); ++i) {
            tmp_solution.taken[i] = (dist(rng) == 1);
        }
        knapsack.eval(tmp_solution);
        if (solution.fitness < tmp_solution.fitness) {
            solution = tmp_solution;
        }
    }
    return solution;
}