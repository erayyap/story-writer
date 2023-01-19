//
// Created by Eray Yapağcı on 19/01/2023.
//
#include "DisplayScript.h"

DisplayScript::DisplayScript(std::unordered_map<std::string,int>* var, std::string s): Script(var) {
    int index = 0;
    for(int i = 0; i < s.length();i ++) {
        if(s[i] == '"') {
            display.emplace_back(s.substr(0,i));
            int j = i + 1;
            while(s[j] != '"' && j < s.length()) {
                j++;
            }
            index = j + 1;
            display.emplace_back(new Equation(vars, s.substr(i + 1, j - i - 1)));

        }
    }
    display.emplace_back(s.substr(index));
}

bool DisplayScript::run() {
    //std::cout << display << std::endl;
    return true;
}

Disp::Disp(std::string s) {
    text = s;
}

Disp::Disp(Equation *e) {
    eq = e;
}

Disp::Disp(const Disp &d) {
    if(eq) {
        eq = d.eq;
    } else {
        text = d.text;
    }
}
