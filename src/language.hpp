#include <string>
#include <map>

using namespace std;

#ifndef BRAINF_CK_INTERPRETER_LANGUAGE_H
#define BRAINF_CK_INTERPRETER_LANGUAGE_H

class bf_language {
public:
    explicit bf_language(int mem_size);

    ~bf_language();

    void set_instructions(const string &instructions_);

    void set_brackets(const map<int, int> &opening_brackets_,
                      const map<int, int> &closing_brackets_);

    void run();

    void run_instruction();

    string instructions;

    int *mem_start_ptr;
    int *mem_ptr;
    int *mem_end_ptr;
    int exec_ptr;

private:
    typedef void (bf_language::*language_method)();

    map<char, bf_language::language_method> method_map = {
            {'>', &bf_language::inc_ptr},
            {'<', &bf_language::dec_ptr},
            {'+', &bf_language::inc_ptr_data},
            {'-', &bf_language::dec_ptr_data},
            {'.', &bf_language::get_ptr},
            {',', &bf_language::put_ptr},
            {'[', &bf_language::loop},
            {']', &bf_language::jmp_loop_start},
    };

    map<int, int> match_opening_brackets;
    map<int, int> match_closing_brackets;

    void inc_ptr();

    void dec_ptr();

    void inc_ptr_data();

    void dec_ptr_data();

    void get_ptr();

    void put_ptr();

    void loop();

    void jmp_loop_start();
};

#endif //BRAINF_CK_INTERPRETER_LANGUAGE_H
