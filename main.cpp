#include <iostream>
#include <string>

#include "Validator.h"
#include "Struct_input.h"

using namespace std;

Validator validator;

int main() {
    printf("Validation starting\n");
    Struct_input s = {"65", "25", "24.6", "14.0"};
    validator.validate(s);
    printf("Validation complete\n");

}

