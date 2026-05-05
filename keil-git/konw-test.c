#include <string.h>
#include <LPC21xx.H>

#define NULL '\0'

enum Result {OK, ERROR};

char g_szInputString[20] = "0xBBBBB"; 

volatile unsigned char g_ucRunTestFlag = 0;   

unsigned int g_uiParsedValue;        
enum Result g_eStatus;               


enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue)
{
    unsigned char ucCharacterCounter;
    unsigned char ucCurrentCharacter;

    *puiValue = 0;
    if((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL))
    {
        return ERROR;
    }
    for(ucCharacterCounter = 2; pcStr[ucCharacterCounter] != NULL ; ucCharacterCounter++)
    {
        ucCurrentCharacter = pcStr[ucCharacterCounter];
        if (ucCharacterCounter == 6)
        {
            return ERROR;
        }
        *puiValue = *puiValue << 4;
        if((ucCurrentCharacter <= '9') && (ucCurrentCharacter >= '0'))
        {
            *puiValue = (*puiValue) | (ucCurrentCharacter - '0');
        }
        else if((ucCurrentCharacter <= 'F') && (ucCurrentCharacter >= 'A'))
        {
            *puiValue = (*puiValue) | (ucCurrentCharacter - 'A' + 10);
        }
        else
        {
            return ERROR;
        }
    }
    return OK;
}

int main(void)
{
    g_eStatus = eHexStringToUInt(g_szInputString, &g_uiParsedValue);

    while(1) 
    {
  
        if (g_ucRunTestFlag == 1)
        {
            g_eStatus = eHexStringToUInt(g_szInputString, &g_uiParsedValue);
            
            g_ucRunTestFlag = 0; 
        }
    }
}