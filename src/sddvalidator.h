//
// Created by tlynch on 7/14/22.
//


#include <string>
#include "Struct_input.h"
#include "validationresults.h"
#include "validationcontext.h"

#ifndef FIRST_SDDVALIDATOR_H
#define FIRST_SDDVALIDATOR_H

using namespace std;

class SddValidator {

    ValidationUtil validationUtil;

public:

    ValidationResults validate(ValidationContext validationContext, ValidationResults validationResults){
        printf("Validating SDD value: %s\n", validationContext.getStructInput().sdd.c_str());
        if(validationUtil.isDouble(validationContext.getStructInput().sdd)){
            double sddValue = stod(validationContext.getStructInput().sdd);
            if(!sddWithinRange(sddValue)){
                validationResults.setSddValid(false);
                validationResults.setSddNotValidMessage("SDD not within acceptable range");
                return validationResults;
            }
        } else {
            validationResults.setSddValid(false);
            validationResults.setSddNotValidMessage("SDD not valid integer input");
            return validationResults;
        }
        validationResults.setSddValid(true);
        return validationResults;
    };

    bool sddWithinRange(double value){
        return value <=20.65 && value > 0;
    }
};

#endif //FIRST_SDDVALIDATOR_H
