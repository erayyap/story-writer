//
// Created by Eray Yapağcı on 17/08/2023.
//

#ifndef STORY_MAKER_LINE_H
#define STORY_MAKER_LINE_H
#include <fstream>
#include <vector>
#include <string>

class Line {
public:
    Line(std::string& s, int d): data(s), depth(d) {};
    static std::vector<Line>* parsePageCode(std::ifstream& stream);

    std::string data;
    int depth;
};


#endif //STORY_MAKER_LINE_H
