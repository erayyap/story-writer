//
// Created by Eray Yapağcı on 17/08/2023.
//

#include "Line.h"

std::vector<Line> *Line::parsePageCode(std::ifstream& stream) {
    auto *lines = new std::vector<Line>;
    char c;
    int depth = 0;
    std::string tempstr;
    while (stream.get(c)) {
        if(c == ';') {
            lines->emplace_back(Line(tempstr, depth));
            tempstr = "";
        } else if(c == '{') {
            lines->emplace_back(Line(tempstr, ++depth));
        } else if(c == '}') {
            lines->emplace_back(Line(tempstr, --depth));
        } else {
            tempstr += c;
        }
     }

        return lines;
}
