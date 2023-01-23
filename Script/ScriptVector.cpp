//
// Created by Eray Yapağcı on 23/01/2023.
//

#include "ScriptVector.h"

ScriptVector::ScriptVector(std::unordered_map<std::string, int> *var, std::ifstream stream) {
    std::string statement;
    scripts = new std::vector<Script*>;
    while(std::getline(stream,statement)) {
        ScriptType type = determineType(statement);
        if(type == ASSIGNMENT) {
            scripts->emplace_back(new AssignmentScript(var,statement));
        }
    }
}

ScriptType ScriptVector::determineType(const std::string& statement) {
    if(statement.substr(0,2) == "//") {
        return COMMENT;
    } else if(statement.substr(0,2) == "if") {
        return IF;
    } else if(statement.substr(0,4) == "else") {
        return ELSE;
    } else if(statement.substr(0,5) == "while") {
        return WHILE;
    } else if(statement.substr(0,7) == "display") {
        return DISPLAY;
    } else if( statement.find('=') != std::string::npos) {
        return ASSIGNMENT;
    } else {
        return EMPTY;
    }
}


void ScriptVector::run() {
    for(Script* s: *scripts) {
        s->run();
    }
}
