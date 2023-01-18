//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_CASESCRIPT_H
#define STORY_MAKER_CASESCRIPT_H
#include "../Equation.h"
#include "Script.h"

enum Compare {
    EQUAL,
    GREATER,
    LOWER,
    EGREATER,
    ELOWER
};

class CaseScript: public Script {
public:
    CaseScript(std::unordered_map<std::string, int> *var,
               Equation *e1, Equation *e2, std::string ope, ScriptType s);
    bool run() override;
protected:
    Equation* LHS;
    Equation* RHS;
    Compare ope;

};

#endif //STORY_MAKER_CASESCRIPT_H
