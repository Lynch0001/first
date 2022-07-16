//
// Created by tlynch on 7/13/22.
//
#ifndef FIRST_STRUCT_INPUT_H
#define FIRST_STRUCT_INPUT_H
#include <string>
using namespace std;

struct Struct_input {

    string sia;
    string sib;
    string sdc;
    string sdd;

    Struct_input(const string &sia, const string &sib, const string &sdc, const string &sdd) : sia(sia), sib(sib),
                                                                                               sdc(sdc), sdd(sdd) {}
};
#endif //FIRST_STRUCT_INPUT_H
