//
// Created by mithrandir on 28/01/2022.
//

#ifndef TP1_KNAPSACK_HPP
#define TP1_KNAPSACK_HPP

#include <vector>
#include "Item.hpp"
#include "string"
#include "Solution.hpp"
#include "memory"
class Knapsack {
public:
    std::vector<Item> items;
    int maxWeight;
    long double beta;

    Knapsack(std::string filename);

    /// \description Permet de calculer la fitness de la solution donnée
    /// \param solution
    void eval(Solution& solution);
    void delta_eval(Solution& solution, int j);

    int get_weight(Solution& solution);
    int get_value(Solution& solution);
    int get_numberItems() const { return items.size(); }
};


#endif //TP1_KNAPSACK_HPP
