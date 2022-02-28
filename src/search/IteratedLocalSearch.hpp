//
// Created by mithrandir on 28/02/2022.
//

#ifndef TP1_ITERATEDLOCALSEARCH_HPP
#define TP1_ITERATEDLOCALSEARCH_HPP

#include "ISearch.hpp"
#include "random"


class IteratedLocalSearch : public ISearch {
    std::mt19937_64 rng;
    std::uniform_int_distribution<int> dist;
    std::uniform_int_distribution<int> random_indice;
    std::uniform_real_distribution<double> random_number;
    int seed;

public:

    IteratedLocalSearch(int seed) {
        this->seed = seed;
        rng = std::mt19937_64(seed);
        dist = std::uniform_int_distribution<int>(0, 1);
        random_number = std::uniform_real_distribution<double>(0, 1);
    }

    Solution search(int cycle, Knapsack &knapsack) override;

    Solution perturbation(Solution solution, Knapsack& knapsack);

};


#endif //TP1_ITERATEDLOCALSEARCH_HPP
