#include <LPC21xx.h>
#define NULL 0

enum Result {ERROR, OK};

enum Result eHexStringToUInt(char pcHexStr[], unsigned int *puiValue){

    unsigned char ucHexDigitIndex;
    unsigned char ucHexDigit;

    *puiValue = 0;

    if((pcHexStr[0] != '0') || (pcHexStr[1] != 'x') || (pcHexStr[2] == NULL)){
        return ERROR;
    }

    for(ucHexDigitIndex = 2; pcHexStr[ucHexDigitIndex] != NULL; ucHexDigitIndex++){

        if(ucHexDigitIndex == 6){
            return ERROR;
        }

        ucHexDigit = pcHexStr[ucHexDigitIndex];

        *puiValue = *puiValue << 4;

        if((ucHexDigit >= '0') && (ucHexDigit <= '9')){
            *puiValue = *puiValue | (ucHexDigit - '0');
        }
        else if((ucHexDigit >= 'A') && (ucHexDigit <= 'F')){
            *puiValue = *puiValue | (ucHexDigit - 'A' + 10);
        }
        else{
            return ERROR;
        }
    }

    return OK;
}

unsigned int testValue1, testValue2;
enum Result testResult1, testResult2;

int main(void) {

	testResult1 = eHexStringToUInt("0x1A3F", &testValue1);
    testResult2 = eHexStringToUInt("0x1G3F", &testValue2);
	

    while(1);
}
'test'