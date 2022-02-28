//
// Created by mithrandir on 28/01/2022.
//

#ifndef TP1_RANDOMSEARCH_HPP
#define TP1_RANDOMSEARCH_HPP


#include "ISearch.hpp"
#include "memory"
#include "random"
class RandomSearch : public ISearch {
    std::mt19937_64 rng;
    std::uniform_int_distribution<int> dist;
public:
    RandomSearch(int seed) {
        rng = std::mt19937_64(seed);
        dist = std::uniform_int_distribution<int> (0, 1);
    }

    Solution search(int cycle, Knapsack& knapsack) override;

};


#endif //TP1_RANDOMSEARCH_HPP
