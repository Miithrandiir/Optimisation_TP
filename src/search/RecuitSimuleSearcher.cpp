//
// Created by mithrandir on 08/02/2022.
//

#include "RecuitSimuleSearcher.hpp"

Solution RecuitSimuleSearcher::search(int cycle, Knapsack &knapsack) {

    Solution solution;
    solution.taken.resize(knapsack.items.size());
    for (int i = 0; i < solution.taken.size(); ++i) {
        solution.taken[i] = (dist(rng) == 1);
    }
    knapsack.eval(solution);

    random_indice = std::uniform_int_distribution<int>(0,solution.taken.size()-1);
    double T = 1;
    while(cycle > 0) {
        double current_fitness = solution.fitness;
        int alea_indice = random_indice(rng);
        solution.taken[alea_indice] = !solution.taken[alea_indice];
        knapsack.eval(solution);
        cycle--;


        double delta =  solution.fitness-current_fitness;

        if(delta <= 0) {
            solution.taken[alea_indice] = !solution.taken[alea_indice];
            solution.fitness = current_fitness;
        } else {

            double u = random_number(rng);

            if(u >= std::exp(delta / T)) {
                solution.taken[alea_indice] = !solution.taken[alea_indice];
                solution.fitness = current_fitness;
            }

        }

        T = 1*T;
    }

    return solution;

}
