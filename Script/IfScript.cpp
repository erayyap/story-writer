//
// Created by Eray Yapağcı on 19/01/2023.
//

#include "IfScript.h"
IfScript::IfScript(std::unordered_map<std::string, int> *var, std::string arg, ScriptVector *sv): Script(var), scriptVector(sv), hasElse(false), boolean(new BoolScript(var, arg)), el(
        nullptr) {}

bool IfScript::run() {
    if(boolean->run()) {
        scriptVector->run();
    } else if(hasElse) {
        el->run();
    }
    return false;
}
void IfScript::setElse(IfScript *e) {
    hasElse = true;
    el = e;
}
