//
// Created by mithrandir on 28/01/2022.
//

#ifndef TP1_ISEARCH_HPP
#define TP1_ISEARCH_HPP

#include "../Solution.hpp"
#include "../Knapsack.hpp"
#include "memory"
class ISearch
{
public:
    virtual Solution search(int cycle, Knapsack& knapsack) = 0;
};

#endif //TP1_ISEARCH_HPP
