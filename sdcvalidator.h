//
// Created by tlynch on 7/14/22.
//


#include <string>
#include "Struct_input.h"
#include "validationresults.h"
#include "validationcontext.h"

#ifndef FIRST_SDCVALIDATOR_H
#define FIRST_SDCVALIDATOR_H

using namespace std;

class SdcValidator {

    ValidationUtil validationUtil;

public:

    ValidationResults validate(ValidationContext validationContext, ValidationResults validationResults){
        printf("Validating SDC value: %s\n", validationContext.getStructInput().sdc.c_str());
        if(validationUtil.isDouble(validationContext.getStructInput().sdc)){
            int sdcValue = stoi(validationContext.getStructInput().sdc);
            if(!sdcWithinRange(sdcValue)){
                validationResults.setSdcValid(false);
                validationResults.setSdcNotValidMessage("SDC not within acceptable range");
                return validationResults;
            }
        } else {
            validationResults.setSdcValid(false);
            validationResults.setSdcNotValidMessage("SDC not valid integer input");
            return validationResults;
        }
        validationResults.setSdcValid(true);
        return validationResults;
    };

    bool sdcWithinRange(int value){
        return value <=40.05 && value > 0;
    }
};

#endif //FIRST_SDCVALIDATOR_H
