//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_DISPLAYSCRIPT_H
#define STORY_MAKER_DISPLAYSCRIPT_H
#include "VarScript.h"
#include "../Variable/Equation.h"
#include <iostream>

union Disp {
    explicit Disp(std::string s);
    explicit Disp(Equation* e);
    Disp(const Disp& d);
    std::string text;
    Equation* eq;

    ~Disp() {
        delete eq;
    }
};

class DisplayScript: public VarScript {
public:

    DisplayScript(std::unordered_map<std::string, int> *var, std::string s);

    int run() override;
private:
    std::vector<Disp> display;
};
#endif //STORY_MAKER_DISPLAYSCRIPT_H
