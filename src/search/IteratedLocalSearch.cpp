//
// Created by mithrandir on 28/02/2022.
//

#include "IteratedLocalSearch.hpp"
#include "HillClimberBestImprovementSearcher.hpp"
Solution IteratedLocalSearch::search(int cycle, Knapsack &knapsack) {

    Solution solution;
    solution.taken.resize(knapsack.items.size());
    for (int i = 0; i < solution.taken.size(); ++i) {
        solution.taken[i] = (dist(rng) == 1);
    }
    random_indice = std::uniform_int_distribution<int>(0,knapsack.items.size()-1);
    knapsack.eval(solution);

    ISearch* search = new HillClimberBestImprovementSearcher(seed);

    Solution s = search->search(cycle/10, knapsack, solution);
    int appelF = cycle/10;
    while(appelF < cycle) {
        Solution sPrime = perturbation(s, knapsack);
        sPrime = search->search(cycle/3, knapsack, sPrime);
        appelF += cycle/3;
        if(sPrime.fitness > s.fitness) {
            s = sPrime;
        }

    }

    delete search;

    return solution;

}

Solution IteratedLocalSearch::perturbation(Solution solution, Knapsack& knapsack) {

    for(int i=0;i<3; ++i)
    {
        int alea_indice = random_indice(rng);
        solution.taken[alea_indice] = !solution.taken[alea_indice];
    }

    return solution;

}
