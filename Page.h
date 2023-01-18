//
// Created by Eray Yapağcı on 16/01/2023.
//

#ifndef STORY_MAKER_PAGE_H
#define STORY_MAKER_PAGE_H
#include <string>
#include <vector>
#include "Script/Script.h"
class Page {
public:
    void run();

private:
    std::string title;
    std::vector<Script>* script;
    std::vector<Page*>* from;

};

#endif //STORY_MAKER_PAGE_H
