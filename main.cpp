#include <iostream>
#include <memory>
#include "src/Knapsack.hpp"
#include "src/search/RandomSearch.hpp"
#include "src/search/RandomWalkerSearcher.hpp"
#include "src/search/HillClimberBestImprovementSearcher.hpp"
#include "chrono"
#include "src/search/HillClimberFirstImprovement.hpp"
#include "src/search/RecuitSimuleSearcher.hpp"

int main(int argc, char *argv[]) {
    std::string filename = argv[1];
    std::string arg2 = argv[2];
    int seed = std::stoi(argv[3]);
    int maxTries = std::stoi(arg2);
    Knapsack knapsack(filename);
    RandomSearch randomSearch(seed);
    RandomWalkerSearcher randomWalkerSearcher(seed);
    HillClimberBestImprovementSearcher hillClimberBestImprovementSearcher(seed);
    HillClimberFirstImprovement hillClimberFirstImprovement(seed);
    RecuitSimuleSearcher recuitSimuleSearcher(seed);

    //RandomSearch
    std::cout << "~ Random Search ~" << std::endl;
    auto start = std::chrono::steady_clock::now();
    Solution solution = randomSearch.search(maxTries, knapsack);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Best fitness: " << solution.get_fitness() << std::endl;
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    std::cout << std::endl;

    //RandomWalkerSearch
    std::cout << "~ Random Walker Search ~" << std::endl;
    start = std::chrono::steady_clock::now();
    Solution solution1 = randomWalkerSearcher.search(maxTries, knapsack);
    end = std::chrono::steady_clock::now();
    std::cout << "Best fitness: " << solution1.get_fitness() << std::endl;
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    std::cout << std::endl;

    //HillClimberBestImprovement
    std::cout << "~ Hill Climber Best Improvement ~" << std::endl;
    start = std::chrono::steady_clock::now();
    Solution solution2 = hillClimberBestImprovementSearcher.search(maxTries, knapsack);
    end = std::chrono::steady_clock::now();
    std::cout << "Best fitness: " << solution2.get_fitness() << std::endl;
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    std::cout << std::endl;

    //HillClimberFirstImprovement
    std::cout << "~ Hill Climber First Improvement ~" << std::endl;
    start = std::chrono::steady_clock::now();
    Solution solution3 = hillClimberFirstImprovement.search(maxTries, knapsack);
    end = std::chrono::steady_clock::now();
    std::cout << "Best fitness: " << solution3.get_fitness() << std::endl;
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout << std::endl;
    //Recuit
    std::cout << "~ Recuit simulé ~" << std::endl;
    start = std::chrono::steady_clock::now();
    Solution solution4 = recuitSimuleSearcher.search(maxTries, knapsack);
    end = std::chrono::steady_clock::now();
    std::cout << "Best fitness: " << solution4.get_fitness() << std::endl;
    elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


    std::cout << std::endl;
    return 0;
}
