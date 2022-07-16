//
// Created by tlynch on 7/13/22.
//
#include <string>

#ifndef FIRST_VALIDATIONRESULTS_H
#define FIRST_VALIDATIONRESULTS_H

using namespace std;

class ValidationResults {
    bool siaValid;
    bool sibValid;
    bool sdcValid;
    bool sddValid;
    string siaNotValidMessage;
    string sibNotValidMessage;
    string sdcNotValidMessage;
    string sddNotValidMessage;
public:

    bool isSiaValid(){return siaValid;};

    void setSiaValid(bool value){siaValid = value;};

    bool isSibValid(){return sibValid;};

    void setSibValid(bool value){sibValid = value;};

    bool isSdcValid(){return sdcValid;};

    void setSdcValid(bool value){sdcValid = value;};

    bool isSddValid(){return sddValid;};

    void setSddValid(bool value){sddValid = value;};

    string getSiaNotValidMessage() { return siaNotValidMessage;};

    void setSiaNotValidMessage(string message) {siaNotValidMessage = message;};

    string getSibNotValidMessage() { return sibNotValidMessage;};

    void setSibNotValidMessage(string message) {sibNotValidMessage = message;};

    string getSdcNotValidMessage() { return sdcNotValidMessage;};

    void setSdcNotValidMessage(string message) {sdcNotValidMessage = message;};

    string getSddNotValidMessage() { return sddNotValidMessage;};

    void setSddNotValidMessage(string message) {sddNotValidMessage = message;};

};


#endif //FIRST_VALIDATIONRESULTS_H
