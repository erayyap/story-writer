//
// Created by Eray Yapağcı on 16/08/2023.
//

#ifndef STORY_MAKER_VARSCRIPT_H
#define STORY_MAKER_VARSCRIPT_H

#include "../Variable/Equation.h"
#include "Script.h"



class VarScript : public Script {
public:
    explicit VarScript(std::unordered_map<std::string,int>* var): vars(var) {};

protected:
    std::unordered_map<std::string,int>* vars;

};


#endif //STORY_MAKER_VARSCRIPT_H
