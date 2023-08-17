//
// Created by Eray Yapağcı on 17/01/2023.
//
#include "Equation.h"

Equation::Equation(std::unordered_map<std::string,int>* var, std::string arg) {
    vars = var;
    arg.erase(std::remove_if(arg.begin(), arg.end(), ::isspace), arg.end());
    int precedence = 0;
    int depth = 0;
    std::stack<char> ope;
    for(int i = 0; i < arg.length(); i++){
        char c = arg[i];
        if(std::isdigit(c)) {
            std::string var = "";
            while(i < arg.length() && std::isdigit(c)) {
                var+= arg[i];
                i++;
            }
            i--;
            token.emplace_back(std::stoi(var));
        } else if(isOperator(c)) {
            if(ope.empty()) {
                ope.push(c);
            } else {
                while(!ope.empty() && getPrecedence(c) < getPrecedence(ope.top())) {
                    token.emplace_back(ope.top());
                    ope.pop();
                }
                ope.push(c);
            }
        } else if(c == '(') {
            ope.push(c);
        } else if(c == ')') {
            while(ope.top() != '(') {
                token.emplace_back(ope.top());
                ope.pop();
            }
            ope.pop();
        } else {
            std::string var = "";
            while(i < arg.length() && !isOperator(c) && c != '(' && c!= ')') {
                var+= arg[i];
                i++;
            }
            i--;
            token.emplace_back(&(*vars)["var"]);
        }
        while(!ope.empty()) {
            token.emplace_back(ope.top());
            ope.pop();
        }
    }
}

bool Equation::isOperator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

int Equation::getPrecedence(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

int Equation::calculate() {
    std::stack<double> stack;
    for(Token& t: token) {
        if(t.getType() != 2){
            stack.push(t.r());
        } else {
            double o1 = stack.top();
            stack.pop();
            double o2 = stack.top();
            stack.pop();
            switch (t.r()) {
                case 1:
                    stack.push(o1 + o2);
                    break;
                case 2:
                    stack.push(o1 - o2);
                    break;
                case 3:
                    stack.push(o1 * o2);
                    break;
                case 4:
                    stack.push(o1 / o2);
                    break;
            }
        }
    }
    return stack.top();
}


