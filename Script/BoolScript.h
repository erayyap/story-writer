//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_BOOLSCRIPT_H
#define STORY_MAKER_BOOLSCRIPT_H
#include "../Equation.h"
#include "Script.h"

enum Compare {
    EQUAL,
    GREATER,
    LOWER,
    EGREATER,
    ELOWER
};

class BoolScript: public Script {
public:
    BoolScript(std::unordered_map<std::string, int> *var,
               std::string arg);
    bool run() override;
protected:
    Equation* LHS;
    Equation* RHS;
    Compare ope;

};

#endif //STORY_MAKER_BOOLSCRIPT_H
