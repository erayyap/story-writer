//
// Created by Eray Yapağcı on 08/01/2023.
//

#include "Page.h"

Page::Page(std::unordered_map<std::string, int> *var, const std::string& fileName): vars(var) {
    std::ifstream code(fileName);
    title = fileName.substr(0, fileName.length() - 4);
    if (!code.is_open()) {
        std::cout << "The file " << fileName << " doesn't exist!"  << std::endl;
    }


}

