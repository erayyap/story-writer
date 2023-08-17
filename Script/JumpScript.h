//
// Created by Eray Yapağcı on 16/08/2023.
//

#ifndef STORY_MAKER_JUMPSCRIPT_H
#define STORY_MAKER_JUMPSCRIPT_H

#include "Script.h"

class JumpScript: public Script {
public:
    explicit JumpScript(int jA): jumpAmount(jA) {};
    int run() override {
        return jumpAmount;
    }

protected:
    int jumpAmount;

};


#endif //STORY_MAKER_JUMPSCRIPT_H
