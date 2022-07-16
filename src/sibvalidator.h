//
// Created by tlynch on 7/14/22.
//


#include <string>
#include "Struct_input.h"
#include "validationresults.h"
#include "validationcontext.h"
#include "validationutil.h"

#ifndef FIRST_SIBVALIDATOR_H
#define FIRST_SIBVALIDATOR_H

using namespace std;

class SibValidator {

    ValidationUtil validationUtil;

public:

    ValidationResults validate(ValidationContext validationContext, ValidationResults validationResults){
        printf("Validating SIB value: %s\n", validationContext.getStructInput().sib.c_str());
        if(validationUtil.isInteger(validationContext.getStructInput().sib)){
            int sibValue = stoi(validationContext.getStructInput().sib);
            if(!sibWithinRange(sibValue)){
                validationResults.setSibValid(false);
                validationResults.setSibNotValidMessage("SIB not within acceptable range");
                return validationResults;
            }
        } else {
            validationResults.setSibValid(false);
            validationResults.setSibNotValidMessage("SIB not valid integer input");
            return validationResults;
        }
        validationResults.setSibValid(true);
        return validationResults;
    };

    bool sibWithinRange(int value){
        return value <=150 && value > 0;
    }
};

#endif //FIRST_SIBVALIDATOR_H
