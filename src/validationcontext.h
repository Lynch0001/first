//
// Created by tlynch on 7/13/22.
//

#include <string>
#include "Struct_input.h"

#ifndef FIRST_VALIDATIONCONTEXT_H
#define FIRST_VALIDATIONCONTEXT_H

using namespace std;

class ValidationContext {
    string structReviewField;
    Struct_input structInput;
public:

    ValidationContext(Struct_input structInput) : structInput(structInput) {}

    const string &getStructReviewField() const {
        return structReviewField;
    }

    void setStructReviewField(const string &structReviewField) {
        ValidationContext::structReviewField = structReviewField;
    }

    const Struct_input &getStructInput() const {
        return structInput;
    }

    void setStructInput(const Struct_input &structInput) {
        ValidationContext::structInput = structInput;
    }

};
#endif //FIRST_VALIDATIONCONTEXT_H
