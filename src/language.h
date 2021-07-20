#include <string>

using namespace std;

#ifndef BRAINF_CK_INTERPRETER_LANGUAGE_H
#define BRAINF_CK_INTERPRETER_LANGUAGE_H

class bf_language {
public:
    int *mem_ptr;
    int *data_ptr;
    int exec_ptr;

    explicit bf_language(int mem_size);

    void instruction_handler(const string &instructions_);

    void run();

    static void inc_ptr(bf_language *lang);

    static void dec_ptr(bf_language *lang);

    static void inc_ptr_data(bf_language *lang);

    static void dec_ptr_data(bf_language *lang);

    static void get_ptr(bf_language *lang);

    static void put_ptr(bf_language *lang);

    static void loop(bf_language *lang);

    static void end_loop(bf_language *lang);

private:
    string instructions;
};

#endif //BRAINF_CK_INTERPRETER_LANGUAGE_H
