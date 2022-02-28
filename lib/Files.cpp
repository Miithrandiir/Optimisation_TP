//
// Created by mithrandir on 21/01/2022.
//

#include "Files.hpp"
#include <fstream>


std::string Files::read_file(std::string filename) {
    std::ifstream fstream;
    fstream.open(filename, std::ios::in);
    if(!fstream.is_open())
        std::cout << "unable to load the file" << std::endl;
    std::string txt;
    //i=0 => Number of objet
    //i=1 => 
    int i = 0;
    while(std::getline(fstream, txt)){
        std::cout << txt << std::endl;
        i++;
    }

    return "";
}
