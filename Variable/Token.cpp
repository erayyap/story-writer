//
// Created by Eray Yapağcı on 19/01/2023.
//

#include "Token.h"

Token::Token(int num) {
    type = NUMBER;
    this->num = num;
}

Token::~Token() {
    delete numAddress;
}

Token::Token(int *address) {
    type = VARIABLE;
    numAddress = address;
}

Token::Token(char ope) {
    type = OPERATOR;
    if(ope == '+') num = 1;
    if(ope == '-') num = 2;
    if(ope == '*') num = 3;
    if(ope == '/') num = 4;
}

int Token::r() {
    if(type == 1) {
        return *numAddress;
    } else {
        return num;
    }
}

int Token::getType() const {return type;}
