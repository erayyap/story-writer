//
// Created by Eray Yapağcı on 17/01/2023.
//

#ifndef STORY_MAKER_EQUATION_H
#define STORY_MAKER_EQUATION_H
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <cstdint>
#include <stack>
#include "Token.h"

class Equation {
public:
    Equation(std::unordered_map<std::string,int>* var, std::string arg);
    int calculate();
private:
    bool static isOperator(char c);
    int static getPrecedence(char c);
    std::unordered_map<std::string,int>* vars;
    std::vector<Token> token;

};


#endif //STORY_MAKER_EQUATION_H
