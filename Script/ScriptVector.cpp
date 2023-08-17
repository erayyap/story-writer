//
// Created by Eray Yapağcı on 23/01/2023.
//

#include "ScriptVector.h"

ScriptVector::ScriptVector(std::unordered_map<std::string, int> *var, std::ifstream stream) {
    struct JumpHeapStruct {
        int jumpAmount;
        int index;

        JumpHeapStruct(int jA, int i) : jumpAmount(jA), index(i) {}

        // Define the comparison function for the priority_queue
        bool operator>(const JumpHeapStruct& other) const {
            return index > other.index;
        }
    };

    auto lines = Line::parsePageCode(stream);
    scripts = new std::vector<Script*>;
    std::priority_queue<JumpHeapStruct, std::vector<JumpHeapStruct>, std::greater<JumpHeapStruct>> jumpHeap;
    for(int i = 0; i < lines->size(); i++) {
        auto line = (*lines)[i];
        ScriptType type = determineType(line.data);
        if(jumpHeap.top().index == i) {
            scripts->emplace_back(new JumpScript(jumpHeap.top().jumpAmount));
            jumpHeap.pop();
        }
        if(type == ASSIGNMENT) {
            scripts->emplace_back(new AssignmentScript(var,line.data));
        } else if(type == DISPLAY) {
            scripts->emplace_back(new DisplayScript(var,line.data));
        } else if(type == IF) {
            int jumpAmount = determineDepthWidth(lines, i) + 1;
            int ifEnd = jumpAmount + i;
            ScriptType endScriptType = determineType((*lines)[ifEnd].data);
            BoolScript* boolean = extractBoolFromParantheses(var, line.data);
            if(endScriptType == ELSE) {
                jumpAmount++;
            }
            scripts->emplace_back(new ConditionalJumpScript(jumpAmount, boolean));
        } else if(type == ELSE) {
            int jumpAmount = determineDepthWidth(lines, i) + 1;
            scripts->emplace_back(new JumpScript(jumpAmount));
        } else if(type == WHILE) {
            int jumpAmount = determineDepthWidth(lines, i) + 1;
            int whileEnd = jumpAmount + i;
            BoolScript* boolean = extractBoolFromParantheses(var, line.data);
            jumpHeap.push(JumpHeapStruct(-jumpAmount, whileEnd));
            scripts->emplace_back(new ConditionalJumpScript(jumpAmount, boolean));
        }
    }
}

ScriptType ScriptVector::determineType(const std::string &line) {
    if (line.substr(0, 2) == "//") {
        return COMMENT;
    } else if (line.find('(') != std::string::npos && line.find(')') != std::string::npos) {
        if (line.substr(0, 2) == "if") {
            return IF;
        } else if (line.substr(0, 4) == "else") {
            return ELSE;
        } else if (line.substr(0, 5) == "while") {
            return WHILE;
        } else if (line.substr(0, 7) == "display") {
            return DISPLAY;
        }
    } else if (line.find('=') != std::string::npos) {
        return ASSIGNMENT;
    } else {
        return EMPTY;
    }
}


int ScriptVector::run() {
    int i = 0;
    while(i < scripts->size()) {
        int jump = (*scripts)[i]->run();
        i += jump;
    }
    return 1;
}

int ScriptVector::determineDepthWidth(std::vector<Line> *lines, int index) {
    int initIndex = index++;
    int initDepth = (*lines)[index].depth;
    while(initDepth < (*lines)[index].depth) {
        if(determineType((*lines)[index].data) == WHILE) {
            index++;
        }
        index++;
    }

    return initIndex - index;
}

BoolScript *ScriptVector::extractBoolFromParantheses(std::unordered_map<std::string, int> *var, const std::string &line) {
    size_t openingParen = line.find('(');
    size_t closingParen = line.rfind(')');
        return new BoolScript(var, line.substr(openingParen + 1, closingParen - openingParen - 1));


}
