#include <cstdlib>
#include <iostream>
#include <functional>
#include <map>
#include "language.h"

using namespace std;

bf_language::bf_language(int mem_size) {
    mem_ptr = (int *) malloc(mem_size * sizeof(int));
    if (!mem_ptr) return;

    data_ptr = mem_ptr;
    exec_ptr = 0;
}

void bf_language::instruction_handler(const string &instructions_) {
    instructions = instructions_;
}

void bf_language::run() {
    while (exec_ptr < instructions.size()) {
        char instruction = instructions[exec_ptr];

        map<char, > func_map = {
                {'>', inc_ptr},
                {'<', dec_ptr},
                {'+', inc_ptr_data},
                {'-', dec_ptr_data},
                {'.', get_ptr},
                {',', put_ptr},
                {'[', loop},
                {']', end_loop}
        };

        static_func func = func_map['>'];
        (*func)(this);

//        switch (instruction) {
//            case '>':
//                inc_ptr();
//                break;
//            case '<':
//                dec_ptr();
//                break;
//            case '+':
//                inc_ptr_data();
//                break;
//            case '-':
//                dec_ptr_data();
//                break;
//            case '.':
//                get_ptr();
//                break;
//            case ',':
//                put_ptr();
//                break;
//            case '[':
//                loop();
//                break;
//            case ']':
//                end_loop();
//                break;
//            default:
//                continue;
//        }
        exec_ptr++;
    }
}

void bf_language::inc_ptr(bf_language *lang) {

}

void bf_language::dec_ptr(bf_language *lang) {

}

void bf_language::inc_ptr_data(bf_language *lang) {

}

void bf_language::dec_ptr_data(bf_language *lang) {

}

void bf_language::get_ptr(bf_language *lang) {

}

void bf_language::put_ptr(bf_language *lang) {

}

void bf_language::loop(bf_language *lang) {

}

void bf_language::end_loop(bf_language *lang) {

}
