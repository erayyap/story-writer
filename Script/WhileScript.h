//
// Created by Eray Yapağcı on 19/01/2023.
//

#ifndef STORY_MAKER_WHILESCRIPT_H
#define STORY_MAKER_WHILESCRIPT_H
#include "ScriptVector.h"

class WhileScript: public Script {
public:
    WhileScript(std::unordered_map<std::string, int> *var, std::string arg, ScriptVector* sv): Script(var), boolean(new BoolScript(var, arg)), scriptVector(sv){};
    bool run() override {
        while(boolean->run()) {
            scriptVector->run();
        }
    }
private:
    bool hasElse;
    BoolScript* boolean;
    ScriptVector* scriptVector;
};

#endif //STORY_MAKER_WHILESCRIPT_H
