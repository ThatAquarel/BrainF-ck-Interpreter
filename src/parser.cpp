#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "parser.h"
#include "language.h"

using namespace std;

char allowed_chars[8] = {'>', '<', '+', '-', '.', ',', '[', ']'};

void parse_file(string &text, const string &filename) {
    stringstream text_stream;
    ifstream file(filename);

    while (getline(file, text, '\n')) text_stream << text;
    getline(text_stream, text);
    file.close();
}

void parse_instructions(string &text, bf_language *lang) {
    string instructions;
    stringstream instruction_stream;

    for (char &c : text) {
        char *c_ptr = find(begin(allowed_chars), end(allowed_chars), c);

        if (c_ptr != end(allowed_chars)) {
            instruction_stream << c;
//            (*lang).instruction_handler(nullptr);
        }
    }

    getline(instruction_stream, instructions);
    (*lang).instruction_handler(instructions);
}
