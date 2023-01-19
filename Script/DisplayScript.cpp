//
// Created by Eray Yapağcı on 19/01/2023.
//
#include "DisplayScript.h"

DisplayScript::DisplayScript(std::unordered_map<std::string,int>* var, std::string s): Script(var) {
    for(int i = 0; i < s.length();i ++) {
        if(s[i] == '"') {
            int j = i + 1;
            while(s[j] != '"' && j < s.length()) {
                j++;
            }
            std::string varName = s.substr(i + 1, j - i - 1);
            if(vars->count(varName) > 0) {
                s.replace(i, j - i + 1, std::to_string((*vars)[varName]));
                i += std::to_string((*vars)[varName]).length() - 1;
            }
        }
    }
    display = s;
}

bool DisplayScript::run() {
    std::cout << display << std::endl;
    return true;
}

