//
// Created by mithrandir on 08/02/2022.
//

#include "HillClimberFirstImprovement.hpp"

Solution HillClimberFirstImprovement::search(int cycle, Knapsack &knapsack) {

    Solution solution;
    solution.taken.resize(knapsack.items.size());
    for (int i = 0; i < solution.taken.size(); ++i) {
        solution.taken[i] = (dist(rng) == 1);
    }
    knapsack.eval(solution);
    int appel_f = 1;
    dist = std::uniform_int_distribution<int>(0, solution.taken.size() - 1);

    while (appel_f < cycle) {
        //Sauvegarde du fitness courant
        double fitness_current = solution.fitness;
        //je sauvegarde x' aléatoire
        int j_best = dist(rng);
        double fitness_best = -100;

        //Changement d'un bit
        solution.taken[j_best] = !solution.taken[j_best];
        //Calcul de l'évaluation de x'
        knapsack.eval(solution);
        //état initial
        solution.taken[j_best] = !solution.taken[j_best];
        appel_f++;
        //Sauvegarde l'eval
        fitness_best = solution.fitness;

        std::vector<int> nb_voisins;
        while (fitness_current >= fitness_best and nb_voisins.size() < solution.taken.size() and appel_f < cycle) {

            int j_random = dist(rng);
            //Tant que l'on trouve un élément déjà déplacé ...
            //Sans remise
            while (std::find(nb_voisins.begin(), nb_voisins.end(), j_random) != nb_voisins.end()) {
                j_random = dist(rng);
            }

            solution.taken[j_random] = !solution.taken[j_random];
            knapsack.eval(solution);
            solution.taken[j_random] = !solution.taken[j_random];
            appel_f++;
            //Si le voisin n'a pas encore été enregistré
            //Avec remise
            //if (std::find(nb_voisins.begin(), nb_voisins.end(), j_random) == nb_voisins.end()) {
                nb_voisins.push_back(j_random);
            //}

            j_best = j_random;
            fitness_best = solution.fitness;

        }

        solution.fitness = fitness_current;
        if (solution.fitness > fitness_best) {
            //On ne trouve pas mieux, donc optimum local !
            return solution;
        }
        //Si on a trouvé une meilleure solution alors on change !
        solution.taken[j_best] = !solution.taken[j_best];
        solution.fitness = fitness_best;
    }


    return solution;

}
