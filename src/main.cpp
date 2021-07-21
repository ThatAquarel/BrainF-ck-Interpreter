#include <iostream>
#include <string>
#include <sstream>
#include <sys/stat.h>

#include "parser.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "Provide 2 arguments, a path to a BrainFuck source file (*.b) "
                "and an integer for the number of cells." << endl;
        return -1;
    }

    string filename = argv[1];

    struct stat buffer{};
    if (stat(filename.c_str(), &buffer) != 0) {
        cerr << "File \"" << filename << "\" does not exist." << endl;
        return -1;
    }

    stringstream str_stream(argv[2]);
    int mem_size;
    if (!(str_stream >> mem_size)) {
        cerr << "\"" << argv[2] << "\" is not a number." << endl;
        return -1;
    }
    if (!str_stream.eof()) {
        cerr << "Trailing characters after number." << endl;
        return -1;
    }

    string text;
    parse_file(text, filename);

    auto *lang = new bf_language(mem_size);
    parse_instructions(text, lang);
    parse_brackets(lang->instructions, lang);

    lang->run();

    delete lang;
    return 0;
}
