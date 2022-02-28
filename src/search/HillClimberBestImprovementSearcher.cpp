//
// Created by mithrandir on 01/02/2022.
//

#include "HillClimberBestImprovementSearcher.hpp"

Solution HillClimberBestImprovementSearcher::search(int cycle, Knapsack &knapsack) {

    Solution solution;
    solution.taken.resize(knapsack.items.size());
    for (int i = 0; i < solution.taken.size(); ++i) {
        solution.taken[i] = (dist(rng) == 1);
    }
    knapsack.eval(solution);

    return search(cycle, knapsack, solution);

}

Solution HillClimberBestImprovementSearcher::search(int cycle, Knapsack &knapsack, Solution &solution) {
    int appel_f = 0;

    while(appel_f < cycle){

        int j_best = -1;
        double fitness_best = -100;
        double fitness_current = solution.fitness;
        //On parcourt tous les bits possibles !
        for (int j = 0; j < solution.taken.size(); j++) {

            //On change un bit
            solution.taken[j] = !solution.taken[j];

            appel_f++;
            knapsack.eval(solution);
            //Si meilleur que la valeur actuelle
            if (fitness_best < solution.fitness) {
                fitness_best = solution.fitness;
                j_best = j;
            }
            //On remet le bit à son état initial
            solution.taken[j] = !solution.taken[j];
        }
        solution.fitness = fitness_current;
        if(solution.fitness > fitness_best) {
            //On ne trouve pas mieux, donc optimum local !
            return solution;
        }
        //Si on a trouvé une meilleure solution alors on change !
        solution.taken[j_best] = !solution.taken[j_best];
        solution.fitness = fitness_best;
    }


    return solution;
}

