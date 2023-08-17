//
// Created by Eray Yapağcı on 19/01/2023.
//

#ifndef STORY_MAKER_SCRIPTVECTOR_H
#define STORY_MAKER_SCRIPTVECTOR_H

#include <vector>
#include <utility>
#include <fstream>
#include <queue>
#include "AssignmentScript.h"
#include "BoolScript.h"
#include "DisplayScript.h"
#include "JumpScript.h"
#include "ConditionalJumpScript.h"
#include "../Reader/Line.h"

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

class ScriptVector: public Script {

public:
    explicit ScriptVector(std::vector<Script*>* s): scripts(s){};
    ScriptVector(std::unordered_map<std::string, int> *var, std::ifstream stream);
    int run() override;
private:
    std::vector<Script*>* scripts;
    static ScriptType determineType(const std::string& line);
    static int determineDepthWidth(std::vector<Line>* lines, int index);
    static BoolScript* extractBoolFromParantheses(std::unordered_map<std::string, int> *var, const std::string& line);
};



#endif //STORY_MAKER_SCRIPTVECTOR_H
