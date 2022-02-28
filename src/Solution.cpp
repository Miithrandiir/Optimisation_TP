//
// Created by mithrandir on 28/01/2022.
//

#include "Solution.hpp"

std::ostream &operator<<(std::ostream &os, const Solution &solution) {

    std::cout << "Affichage des solutions : " << std::endl;
    std::cout << "[ ";
    for(bool flag : solution.taken) {
        std:: cout << (flag ? "1" : "0") << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "[Fitness] : " << solution.get_fitness() << std::endl;
    return os;
}
