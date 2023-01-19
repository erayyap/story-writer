//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_ASSIGNMENTSCRIPT_H
#define STORY_MAKER_ASSIGNMENTSCRIPT_H
#include "../Equation.h"
#include "Script.h"

class BoolScript: public Script {
public:
    BoolScript(std::unordered_map<std::string,int>* var, std::string a, Equation* e) : Script(var), argument(a), equation(e){};

    BoolScript(std::unordered_map<std::string, int> *pMap, std::string basicString);

    bool run() override {
        (*vars)[argument] = equation->calculate();
        return true;
    };
protected:
    std::string argument;
    Equation* equation;

};
#endif //STORY_MAKER_ASSIGNMENTSCRIPT_H
