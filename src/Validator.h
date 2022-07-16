//
// Created by tlynch on 7/13/22.
//

#ifndef FIRST_VALIDATOR_H
#define FIRST_VALIDATOR_H
#include <string>
#include <iostream>

#include "Struct_input.h"
#include "validationresults.h"
#include "validationcontext.h"
#include "siavalidator.h"
#include "sibvalidator.h"
#include "sdcvalidator.h"
#include "sddvalidator.h"

using namespace std;

class Validator {

    SiaValidator siaValidator;
    SibValidator sibValidator;
    SdcValidator sdcValidator;
    SddValidator sddValidator;
    ValidationResults validationResults;

public:

    bool validate(Struct_input inputvalue){
        string structfields[] = {"sia", "sib", "sdc", "sdd" };
        ValidationContext validationContext = ValidationContext(inputvalue);
        for(string fieldname:structfields) {
            printf("validating fieldname: %s\n", fieldname.c_str());
            if(fieldname=="sia") {
                validationContext.setStructReviewField("sia");
                validationResults = siaValidator.validate(validationContext, validationResults);
                printf("SIA is valid: %d\n", validationResults.isSiaValid());
            }
            if(fieldname=="sib") {
                validationContext.setStructReviewField("sib");
                validationResults = sibValidator.validate(validationContext, validationResults);
                printf("SIB is valid: %d\n", validationResults.isSibValid());
            }
            if(fieldname=="sdc") {
                validationContext.setStructReviewField("sdc");
                validationResults = sdcValidator.validate(validationContext, validationResults);
                printf("SDC is valid: %d\n", validationResults.isSdcValid());
            }
            if(fieldname=="sdd") {
                validationContext.setStructReviewField("sdd");
                validationResults = sddValidator.validate(validationContext, validationResults);
                printf("SDD is valid: %d\n", validationResults.isSddValid());
            }
        }
        if(validationResults.isSiaValid() &&
           validationResults.isSibValid() &&
           validationResults.isSdcValid() &&
           validationResults.isSddValid()   ){
            printf("Struct input is valid\n");
            return true;
        } else {
            printf("Struct input is not valid\n");
            return false;
        }
    };
};

#endif //FIRST_VALIDATOR_H
