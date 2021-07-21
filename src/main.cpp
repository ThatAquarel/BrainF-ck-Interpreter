#include <filesystem>
#include "parser.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc <= 1) return -1;

    string filename = argv[1];
    if (!filesystem::exists(filename)) return -1;

    string text;
    parse_file(text, filename);

    auto *lang = new bf_language(128);
    parse_instructions(text, lang);
    parse_brackets(text, lang);

    lang->run();

    delete lang;
    return 0;
}
