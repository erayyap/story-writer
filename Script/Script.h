//
// Created by Eray Yapağcı on 16/01/2023.
//

#ifndef STORY_MAKER_SCRIPT_H
#define STORY_MAKER_SCRIPT_H
#include "../Equation.h"

/*enum ScriptType {
    NORMAL,
    IF,
    ELSE,
    WHILE,
    END
};*/

class Script {
public:
    explicit Script(std::unordered_map<std::string,int>* var): vars(var) {};
    //Script(std::unordered_map<std::string,int>* var, ScriptType s): vars(var), scriptType(s) {};
    virtual bool run() = 0;

protected:
    std::unordered_map<std::string,int>* vars;
    //ScriptType scriptType;
};

#endif //STORY_MAKER_SCRIPT_H
