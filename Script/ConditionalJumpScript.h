//
// Created by Eray Yapağcı on 16/08/2023.
//

#ifndef STORY_MAKER_CONDITIONALJUMPSCRIPT_H
#define STORY_MAKER_CONDITIONALJUMPSCRIPT_H

#include "JumpScript.h"
#include "BoolScript.h"

class ConditionalJumpScript: public JumpScript {
public:
    explicit ConditionalJumpScript(int jA, BoolScript* b): JumpScript(jA), boolean(b) {};
    int run() override {
        if(boolean->run()) {
            return jumpAmount;
        } else {
            return 1;
        }
    };

protected:
    BoolScript* boolean;

};



#endif //STORY_MAKER_CONDITIONALJUMPSCRIPT_H
