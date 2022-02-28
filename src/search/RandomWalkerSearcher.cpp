//
// Created by mithrandir on 01/02/2022.
//

#include "RandomWalkerSearcher.hpp"

Solution RandomWalkerSearcher::search(int cycle, Knapsack &knapsack) {
    random_indice = std::uniform_int_distribution<int>(0,knapsack.get_numberItems()-1);

    Solution solution;
    solution.taken.resize(knapsack.items.size());
    for(int i=0; i < solution.taken.size(); ++i) {
        solution.taken[i] = (dist(rng) == 1);
    }
    knapsack.eval(solution);

    Solution bestSolution;
    for(int w=0;w<cycle;++w) {
        int randomIndex=random_indice(rng);
        solution.taken[randomIndex] = !solution.taken[randomIndex];
        knapsack.eval(solution);
        if(bestSolution.fitness < solution.fitness){
            bestSolution = solution;
        }
    }
    return bestSolution;
}
