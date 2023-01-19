//
// Created by Eray Yapağcı on 18/01/2023.
//

#ifndef STORY_MAKER_DISPLAYSCRIPT_H
#define STORY_MAKER_DISPLAYSCRIPT_H
#include "Script.h"
#include <iostream>

class DisplayScript: public Script {
public:

    DisplayScript(std::unordered_map<std::string, int> *var, std::string s);

    bool run() override;
private:
    std::string display;
};
#endif //STORY_MAKER_DISPLAYSCRIPT_H
