#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>

#include "parser.hpp"

using namespace std;

bf_language::bf_language(int mem_size) {
    mem_ptr = new(nothrow) int[mem_size];
    size_t mem_size_bytes = mem_size * sizeof(int);
    if (mem_ptr == nullptr) {
        cerr << "Could not allocate " << mem_size_bytes << " bytes of memory." << endl;
        return;
    }

    memset(mem_ptr, 0, mem_size_bytes);

    mem_start_ptr = mem_ptr;
    mem_end_ptr = mem_ptr + mem_size_bytes;

    exec_ptr = 0;
}

bf_language::~bf_language() {
    delete[] mem_start_ptr;
}

void bf_language::set_instructions(const string &instructions_) {
    instructions = instructions_;
}

void bf_language::set_brackets(const map<int, int> &opening_brackets_,
                               const map<int, int> &closing_brackets_) {
    match_opening_brackets = opening_brackets_;
    match_closing_brackets = closing_brackets_;
}

void bf_language::run() {
    while (exec_ptr < instructions.size()) {
        run_instruction();
        exec_ptr++;
    }
}

void bf_language::run_instruction() {
    assert(mem_ptr >= mem_start_ptr);
    assert(mem_ptr < mem_end_ptr);

    char instruction = instructions[exec_ptr];

    language_method method = method_map[instruction];
    (*this.*method)();
}

void bf_language::inc_ptr() { mem_ptr++; }

void bf_language::dec_ptr() { mem_ptr--; }

void bf_language::inc_ptr_data() { (*mem_ptr)++; }

void bf_language::dec_ptr_data() { (*mem_ptr)--; }

void bf_language::get_ptr() { cout << (char) *mem_ptr; }

void bf_language::put_ptr() { *mem_ptr = getchar(); }

void bf_language::loop() {
    int loop_end = match_opening_brackets[exec_ptr] + 1;
    int *loop_start_mem_ptr = mem_ptr;

    exec_ptr++;
    while (*loop_start_mem_ptr) {
        while (exec_ptr < loop_end && *loop_start_mem_ptr) {
            run_instruction();
            exec_ptr++;
        }
    }
}

void bf_language::end_loop() {
    exec_ptr = match_closing_brackets[exec_ptr];
}
