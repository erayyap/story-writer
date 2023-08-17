//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_BOOLSCRIPT_H
#define STORY_MAKER_BOOLSCRIPT_H
#include "../Variable/Equation.h"
#include "VarScript.h"

enum Compare {
    EQUAL,
    GREATER,
    LOWER,
    EGREATER,
    ELOWER,
    TRUE
};

class BoolScript: public VarScript {
public:
    BoolScript(std::unordered_map<std::string, int> *var,
               std::string arg);
    int run() override;
protected:
    Equation* LHS;
    Equation* RHS;
    Compare ope;

};

#endif //STORY_MAKER_BOOLSCRIPT_H
