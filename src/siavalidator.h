//
// Created by tlynch on 7/14/22.
//


#include <string>
#include "Struct_input.h"
#include "validationresults.h"
#include "validationcontext.h"
#include "validationutil.h"

#ifndef FIRST_SIAVALIDATOR_H
#define FIRST_SIAVALIDATOR_H

using namespace std;

class SiaValidator {

    ValidationUtil validationUtil;

public:

    ValidationResults validate(ValidationContext validationContext, ValidationResults validationResults){
        printf("Validating SIA value: %s\n", validationContext.getStructInput().sia.c_str());
        if(validationUtil.isInteger(validationContext.getStructInput().sia)){
            int siaValue = stoi(validationContext.getStructInput().sia);
            if(!siaWithinRange(siaValue)){
                validationResults.setSiaValid(false);
                validationResults.setSiaNotValidMessage("SIA not within acceptable range");
                return validationResults;
            }
        } else {
            validationResults.setSiaValid(false);
            validationResults.setSiaNotValidMessage("SIA not valid integer input");
            return validationResults;
        }
        validationResults.setSiaValid(true);
        return validationResults;
    };

    bool siaWithinRange(int value){
        return value <=150 && value > 0;
    }
};

#endif //FIRST_SIAVALIDATOR_H
