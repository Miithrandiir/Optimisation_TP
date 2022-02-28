//
// Created by mithrandir on 01/02/2022.
//

#ifndef TP1_HILLCLIMBERBESTIMPROVEMENTSEARCHER_HPP
#define TP1_HILLCLIMBERBESTIMPROVEMENTSEARCHER_HPP


#include "ISearch.hpp"
#include "random"

class HillClimberBestImprovementSearcher : public ISearch {
public:

    HillClimberBestImprovementSearcher(int seed) {
        rng = std::mt19937_64(seed);
        dist = std::uniform_int_distribution<int>(0, 1);
    }

    std::mt19937_64 rng;
    std::uniform_int_distribution<int> dist;

    Solution search(int cycle, Knapsack &knapsack) override;

    Solution search(int cycle, Knapsack &knapsack, Solution &sol) override;
};


#endif //TP1_HILLCLIMBERBESTIMPROVEMENTSEARCHER_HPP
