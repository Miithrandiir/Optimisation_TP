cmake_minimum_required(VERSION 3.21)
project(TP1)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-std=c++14 -O2)
add_executable(TP1 main.cpp lib/Files.cpp lib/Files.hpp src/Solution.cpp src/Solution.hpp src/Knapsack.cpp src/Knapsack.hpp src/Item.hpp src/search/ISearch.hpp src/search/RandomSearch.cpp src/search/RandomSearch.hpp src/search/RandomWalkerSearcher.cpp src/search/RandomWalkerSearcher.hpp src/search/HillClimberBestImprovementSearcher.cpp src/search/HillClimberBestImprovementSearcher.hpp src/search/HillClimberFirstImprovement.cpp src/search/HillClimberFirstImprovement.hpp src/search/RecuitSimuleSearcher.cpp src/search/RecuitSimuleSearcher.hpp src/search/IteratedLocalSearch.cpp src/search/IteratedLocalSearch.hpp)
add_executable(TP1_eval eval.cpp lib/Files.cpp lib/Files.hpp src/Solution.cpp src/Solution.hpp src/Knapsack.cpp src/Knapsack.hpp src/Item.hpp src/search/ISearch.hpp src/search/RandomSearch.cpp src/search/RandomSearch.hpp src/search/RandomWalkerSearcher.cpp src/search/RandomWalkerSearcher.hpp src/search/HillClimberBestImprovementSearcher.cpp src/search/HillClimberBestImprovementSearcher.hpp src/search/HillClimberFirstImprovement.cpp src/search/HillClimberFirstImprovement.hpp src/search/RecuitSimuleSearcher.cpp src/search/RecuitSimuleSearcher.hpp src/search/IteratedLocalSearch.cpp src/search/IteratedLocalSearch.hpp)

