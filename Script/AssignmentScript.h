//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_ASSIGNMENTSCRIPT_H
#define STORY_MAKER_ASSIGNMENTSCRIPT_H
#include "../Equation.h"
#include "Script.h"

class CaseScript: public Script {
public:
    CaseScript(std::unordered_map<std::string,int>* var, std::string a, Equation* e) : Script(var), argument(a), equation(e){};
    bool run() override {
        (*vars)[argument] = equation->calculate();
        return true;
    };
protected:
    std::string argument;
    Equation* equation;

};
#endif //STORY_MAKER_ASSIGNMENTSCRIPT_H
