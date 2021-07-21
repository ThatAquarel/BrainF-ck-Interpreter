#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

#include "parser.h"

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
        }
    }

    getline(instruction_stream, instructions);

    (*lang).set_instructions(instructions);
}

void parse_brackets(string &instructions, bf_language *lang) {
    vector<int> temp;

    map<int, int> opening_brackets;
    map<int, int> closing_brackets;

    char c;
    for (int i = 0; i < instructions.size(); i++) {
        c = instructions[i];

        if (c == '[') {
            temp.push_back(i);
        } else if (c == ']') {
            opening_brackets[temp[temp.size() - 1]] = i;
            closing_brackets[i] = temp[temp.size() - 1];

            temp.pop_back();
        }
    }

    (*lang).set_brackets(opening_brackets, closing_brackets);
}
