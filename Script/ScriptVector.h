//
// Created by Eray Yapağcı on 19/01/2023.
//

#ifndef STORY_MAKER_SCRIPTVECTOR_H
#define STORY_MAKER_SCRIPTVECTOR_H

#include <utility>

#include "AssignmentScript.h"
#include "BoolScript.h"
#include "DisplayScript.h"

class ScriptVector {
public:
    explicit ScriptVector(std::vector<Script*>* s): scripts(s){};
    void run() {
        for(Script* s: *scripts) {
            s->run();
        }
    }
private:
    std::vector<Script*>* scripts;
};
#endif //STORY_MAKER_SCRIPTVECTOR_H
