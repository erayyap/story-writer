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
class Token {
public:
    Token(int num){
        type = 0;
        this->num = num;
    }
    Token(int* address) {
        type = 1;
        numAddress = address;
    }
    Token(char ope) {
        type = 2;
        if(ope == '+') num = 1;
        if(ope == '-') num = 2;
        if(ope == '*') num = 3;
        if(ope == '/') num = 4;
    }
    int r() {
        if(type == 1) {
            return *numAddress;
        } else {
            return num;
        }
    }
    int getType(){return type;};
private:
    uint8_t type;
    int num;
    int* numAddress;
};

class Equation {
public:
    Equation(std::unordered_map<std::string,int>* var, std::string arg);
    int calculate();
private:
    bool static isOperator(char c);
    int static getPrecedence(char c);
    std::unordered_map<std::string,int>* vars;
    std::vector<Token> token;

    static bool isOperator();
};


#endif //STORY_MAKER_EQUATION_H
