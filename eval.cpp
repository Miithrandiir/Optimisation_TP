//
// Created by mithrandir on 08/02/2022.
//

#include <iostream>
#include <fstream>
#include "src/search/ISearch.hpp"
#include "src/search/RandomSearch.hpp"
#include "src/search/RandomWalkerSearcher.hpp"
#include "src/search/HillClimberBestImprovementSearcher.hpp"
#include "src/search/HillClimberFirstImprovement.hpp"
#include "src/search/RecuitSimuleSearcher.hpp"
#include "src/search/IteratedLocalSearch.hpp"

ISearch *get_algorithm(int algo, int seed);

int main(int argc, char *argv[]) {

    //argv 1 => Algo
    //argv 2 => Fichier à lire
    //argv 3 => Nombre de cycle
    //argv 4 => Nombre d'itération
    //argv 5 => Fichier à écrire

    if (argc != 5) {
        std::cout << "usage: ./TP1_eval <Algo> <data_file> <nb Iterations> <writing file>" << std::endl;
        std::cout << "~ Algorithme ~" << std::endl;
        std::cout << "\t - 1: RandomSearch" << std::endl;
        std::cout << "\t - 2: RandomWalkerSearcher" << std::endl;
        std::cout << "\t - 3: HillClimberBestImprovement" << std::endl;
        std::cout << "\t - 4: HillClimberFirstImprovement" << std::endl;
        std::cout << "\t - 5: Recuit simulé" << std::endl;
        std::cout << "\t - 6: Iterated Local Search" << std::endl;
    }

    int algo = std::stoi(argv[1]);
    std::string data_file = argv[2];
    int nb_iteration = std::stoi(argv[3]);
    std::string write_file = argv[4];

    Knapsack knapsack(data_file);

    std::fstream ofstream;
    ofstream.open(write_file);

    ofstream << "Iterations,  Max try, fitness" << std::endl;

    std::vector<int> nb_cycles{100000, 1000000, 10000000};

    for (int cycle: nb_cycles) {
        for (int i = 0; i < nb_iteration; ++i) {

            ISearch *search = get_algorithm(algo, i);
            if (search == nullptr)
                return 2;
            Solution sol = search->search(cycle, knapsack);

            ofstream << i + 1 << "," << cycle << "," << sol.fitness << std::endl;

            delete search;
        }
    }
    ofstream.close();

    return 0;
}

ISearch *get_algorithm(int algo, int seed) {
    switch (algo) {
        case 1:
            return new RandomSearch(seed);
        case 2:
            return new RandomWalkerSearcher(seed);
        case 3:
            return new HillClimberBestImprovementSearcher(seed);
        case 4:
            return new HillClimberFirstImprovement(seed);
        case 5:
            return new RecuitSimuleSearcher(seed);
        case 6:
            return new IteratedLocalSearch(seed);
    }

    return nullptr;
}
