//
// Created by Eray Yapağcı on 19/01/2023.
//

#ifndef STORY_MAKER_SCRIPTVECTOR_H
#define STORY_MAKER_SCRIPTVECTOR_H

#include <vector>
#include <utility>
#include <fstream>
#include "AssignmentScript.h"
#include "BoolScript.h"
#include "DisplayScript.h"
#include "IfScript.h"
#include "WhileScript.h"

enum ScriptType {
    EMPTY,
    COMMENT,
    BOOL,
    ASSIGNMENT,
    DISPLAY,
    IF,
    ELSE,
    WHILE,
};

class ScriptVector {
    static ScriptType determineType(const std::string& statement);

public:
    explicit ScriptVector(std::vector<Script*>* s): scripts(s){};
    ScriptVector(std::unordered_map<std::string, int> *var, std::ifstream stream);
    void run();
private:
    std::vector<Script*>* scripts;
};



#endif //STORY_MAKER_SCRIPTVECTOR_H
