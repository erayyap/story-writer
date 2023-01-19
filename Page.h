//
// Created by Eray Yapağcı on 16/01/2023.
//

#ifndef STORY_MAKER_PAGE_H
#define STORY_MAKER_PAGE_H
#include <string>
#include <vector>
#include "Script/ScriptVector.h"
class Page {
public:
    void run();

private:
    std::string title;
    ScriptVector* script;
    std::vector<Page*>* from;

};

#endif //STORY_MAKER_PAGE_H
