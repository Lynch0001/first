//
// Created by tlynch on 7/14/22.
//

#include <string>
#include "Struct_input.h"

#ifndef FIRST_VALIDATIONUTIL_H
#define FIRST_VALIDATIONUTIL_H

using namespace std;

class ValidationUtil {

public:

    bool isInteger(string value){
        printf("Checking if num is Integer\n");
        for(char v:value){
            if(!isdigit(v) && !(v==45)){
                printf("Number is not an integer\n");
                return false;
            }
        }
        printf("Number is an integer\n");
        return true;
    };

    bool isDouble(string value){
        printf("Checking if num is Double\n");
        for(char v:value){
            if(!isdigit(v) && !isValidNonDigitChar(v)){
                printf("Number is not a double\n");
                return false;
            }
        }
        printf("Number is a double\n");
        return true;
    };

    bool isValidNonDigitChar(char value){
        printf("Checking if char is non-digit\n");

        // comma 44
        // period 46
        // hyphen 45

        if(!(value==44) && !(value==45) && !(value==46)){
            printf("char is not an authorized special character\n");
            return false;
        }

        printf("char is an authorized special character\n");
        return true;
    };

};
#endif //FIRST_VALIDATIONUTIL_H
