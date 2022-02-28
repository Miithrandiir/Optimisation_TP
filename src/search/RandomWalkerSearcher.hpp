//
// Created by mithrandir on 01/02/2022.
//

#ifndef TP1_RANDOMWALKERSEARCHER_HPP
#define TP1_RANDOMWALKERSEARCHER_HPP


#include <random>
#include "ISearch.hpp"

class RandomWalkerSearcher : public ISearch {

    std::mt19937_64 rng;
    std::uniform_int_distribution<int> dist;
    std::uniform_int_distribution<int> random_indice;
public:
    RandomWalkerSearcher(int seed) {
        rng = std::mt19937_64(seed);
        dist = std::uniform_int_distribution<int> (0, 1);

    }

    Solution search(int cycle, Knapsack &knapsack) override;
};


#endif //TP1_RANDOMWALKERSEARCHER_HPP
