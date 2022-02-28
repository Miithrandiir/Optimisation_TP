//
// Created by mithrandir on 08/02/2022.
//

#ifndef TP1_HILLCLIMBERFIRSTIMPROVEMENT_HPP
#define TP1_HILLCLIMBERFIRSTIMPROVEMENT_HPP


#include "ISearch.hpp"
#include "random"
#include "vector"
#include "algorithm"

class HillClimberFirstImprovement : public ISearch {
private:
    std::mt19937_64 rng;
    std::uniform_int_distribution<int> dist;
public:

    HillClimberFirstImprovement(int seed) {
        rng = std::mt19937_64(seed);
        dist = std::uniform_int_distribution<int>(0, 1);
    }


    Solution search(int cycle, Knapsack &knapsack) override;


};


#endif //TP1_HILLCLIMBERFIRSTIMPROVEMENT_HPP
