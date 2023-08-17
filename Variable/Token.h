//
// Created by Eray Yapağcı on 19/01/2023.
//

#ifndef STORY_MAKER_TOKEN_H
#define STORY_MAKER_TOKEN_H
#include <cstdint>
class Token {
    enum type {
        NUMBER,
        VARIABLE,
        OPERATOR
    };
public:
    explicit Token(int num);
    ~Token();
    explicit Token(int* address);
    explicit Token(char ope);
    int r();
    int getType() const;
private:
    uint8_t type;
    int num;
    int* numAddress;
};


#endif //STORY_MAKER_TOKEN_H
