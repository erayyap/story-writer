//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_ASSIGNMENTSCRIPT_H
#define STORY_MAKER_ASSIGNMENTSCRIPT_H
#include "../Variable/Equation.h"
#include "Script.h"

class AssignmentScript: public Script {
public:
    AssignmentScript(std::unordered_map<std::string,int>* var, const std::string& statement) : Script(var),
    variable(&(*var)[statement.substr(0,statement.find('=') - 1)]),
    equation(new Equation(var,statement.substr(statement.find('=') + 1 ))){};

    bool run() override {
        *variable = equation->calculate();
        return true;
    };
protected:
    int* variable;
    Equation* equation;

};
#endif //STORY_MAKER_ASSIGNMENTSCRIPT_H
