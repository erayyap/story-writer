//
// Created by Eray Yapağcı on 16/01/2023.
//

#ifndef STORY_MAKER_BOOK_H
#define STORY_MAKER_BOOK_H
#include <unordered_map>
#include <iostream>
#include "Page.h"
class Book {

private:
    std::unordered_map<std::string,int>* vars;
    std::vector<Page*>* pages;

};
#endif //STORY_MAKER_BOOK_H
