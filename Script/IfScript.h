//
// Created by Eray Yapağcı on 19/01/2023.
//
#ifndef STORY_MAKER_IFSCRIPT_H
#define STORY_MAKER_IFSCRIPT_H
#include "ScriptVector.h"
class IfScript: public Script {
public:
    IfScript(std::unordered_map<std::string, int> *var, std::string arg, ScriptVector* sv);
    bool run() override;
    void setElse(IfScript* e);
private:
    bool hasElse;
    BoolScript* boolean;
    ScriptVector* scriptVector;
    IfScript* el;
};
#endif //STORY_MAKER_IFSCRIPT_H