//
// Created by Eray Yapağcı on 18/01/2023.
//
#include "BoolScript.h"

BoolScript::BoolScript(std::unordered_map<std::string, int> *var, std::string arg): Script(var)  {
    int index = 0;
    int space = 0;
    if (arg.find("==") != std::string::npos) {
        index = arg.find("==");
        space = 2;
        ope = EQUAL;
    } else if(arg.find(">=") != std::string::npos) {
        index = arg.find(">=");
        space = 2;
        ope = EGREATER;
    } else if(arg.find("=>") != std::string::npos) {
        index = arg.find("=>");
        space = 2;
        ope = EGREATER;
    } else if(arg.find("<=") != std::string::npos) {
        index = arg.find("<=");
        space = 2;
        ope = ELOWER;
    } else if(arg.find("=<") != std::string::npos) {
        index = arg.find("=<");
        space = 2;
        ope = ELOWER;
    } else if(arg.find("<") != std::string::npos) {
        index = arg.find("<");
        space = 1;
        ope = LOWER;
    } else if(arg.find(">") != std::string::npos) {
        index = arg.find(">");
        space = 1;
        ope = GREATER;
    }
    LHS = new Equation(vars, arg.substr(0,index) );
    RHS = new Equation(vars, arg.substr(index + space) );
}

bool BoolScript::run() {
    return LHS->calculate() == RHS->calculate();
}
