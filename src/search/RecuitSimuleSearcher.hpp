//
// Created by mithrandir on 08/02/2022.
//

#ifndef TP1_RECUITSIMULESEARCHER_HPP
#define TP1_RECUITSIMULESEARCHER_HPP


#include "ISearch.hpp"
#include "random"

class RecuitSimuleSearcher : public ISearch {
    std::mt19937_64 rng;
    std::uniform_int_distribution<int> dist;
    std::uniform_int_distribution<int> random_indice;
    std::uniform_real_distribution<double> random_number;

public:

    RecuitSimuleSearcher(int seed) {
        rng = std::mt19937_64(seed);
        dist = std::uniform_int_distribution<int> (0, 1);
        random_number = std::uniform_real_distribution<double> (0, 1);
    }

    Solution search(int cycle, Knapsack &knapsack) override;
};


#endif //TP1_RECUITSIMULESEARCHER_HPP
