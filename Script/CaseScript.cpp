//
// Created by Eray Yapağcı on 18/01/2023.
//
#include "CaseScript.h"

CaseScript::CaseScript(std::unordered_map<std::string, int> *var,
                       Equation *e1, Equation *e2, std::string ope, ScriptType s) : Script(var,s), LHS(e1), RHS(e2) {
        if(ope == "==") this->ope = EQUAL;
        else if(ope == "<") this->ope = LOWER;
        else if(ope == ">") this->ope = GREATER;
        else if(ope == "<=" || ope == "=<") this->ope = ELOWER;
        else if(ope == ">=" || ope == "=>") this->ope =  EGREATER;
}

bool CaseScript::run() {
    return LHS->calculate() == RHS->calculate();
}

