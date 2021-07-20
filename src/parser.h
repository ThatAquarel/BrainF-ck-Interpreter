#include <string>
#include "language.h"

using namespace std;

#ifndef BRAINF_CK_INTERPRETER_STRING_UTIL_H
#define BRAINF_CK_INTERPRETER_STRING_UTIL_H

void parse_file(string &text, const string &filename);

//void parse_instructions(string &text, void (*instruction_handler)(char));
//void parse_instructions(string &text, void (bf_language::*instruction_handler)(char), bf_language &lang);
void parse_instructions(string &text, bf_language *lang);

#endif //BRAINF_CK_INTERPRETER_STRING_UTIL_H
