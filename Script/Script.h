//
// Created by Eray Yapağcı on 16/01/2023.
//

#ifndef STORY_MAKER_SCRIPT_H
#define STORY_MAKER_SCRIPT_H
#include "../Variable/Equation.h"



class Script {
public:
    explicit Script(std::unordered_map<std::string,int>* var): vars(var) {};
    virtual bool run() = 0;

protected:
    std::unordered_map<std::string,int>* vars;

};

#endif //STORY_MAKER_SCRIPT_H
