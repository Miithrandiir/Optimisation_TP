//
// Created by mithrandir on 28/01/2022.
//

#include "Knapsack.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

Knapsack::Knapsack(std::string filename) {
    std::ifstream fstream;
    fstream.open(filename, std::ios::in);
    if (!fstream.is_open())
        std::cout << "unable to load the file" << std::endl;
    std::string txt;

    //Number of items
    std::getline(fstream, txt);
    items.reserve(std::stoi(txt));
    //Lecture Valeurs
    std::getline(fstream, txt);
    std::stringstream values(txt);
    int i = 0;
    for (std::string numbers; std::getline(values, numbers, ' ');) {
        items.emplace_back(0, std::stoi(numbers));
        ++i;
    }

    i = 0;
    //Lecture Poids
    std::getline(fstream, txt);
    std::stringstream weights(txt);
    for (std::string numbers; std::getline(weights, numbers, ' ');) {
        items[i].weight = std::stoi(numbers);
        ++i;
    }

    //Number of max of weight
    std::getline(fstream, txt);
    maxWeight = std::stoi(txt);


    beta = std::numeric_limits<double>::min();
    for (int i = 0; i < items.size(); ++i) {
        double calc = (double) items[i].value / (double) items[i].weight;
        if (calc > beta) {
            beta = calc;
        }
    }
}




void Knapsack::eval(Solution &solution) {

    solution.z = get_value(solution);
    solution.w = get_weight(solution);

    if (solution.w <= maxWeight) {
        solution.fitness = solution.z;
        return;
    }

    solution.fitness = solution.z - beta * (solution.w - maxWeight);
}

int Knapsack::get_weight(Solution &solution) {
    int somme = 0;

    for (int i = 0; i < solution.taken.size(); ++i) {
        if (solution.taken[i]) {
            somme += items[i].weight;
        }
    }
    return somme;
}

int Knapsack::get_value(Solution &solution) {
    int somme = 0;

    for (int i = 0; i < solution.taken.size(); ++i) {
        if (solution.taken[i]) {
            somme += items[i].value;
        }
    }
    return somme;
}

void Knapsack::delta_eval(Solution &solution,int j) {

    if(solution.taken[j] == 0) {
        solution.z = solution.z + items[j].value;
        solution.w = solution.z + items[j].weight;
    } else {
        solution.z = solution.z - items[j].value;
        solution.w = solution.z - items[j].weight;
    }

    if (solution.w <= maxWeight) {
        solution.fitness = solution.z;
        return;
    }

    solution.fitness = solution.z - beta * (solution.w - maxWeight);


}

