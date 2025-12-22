
#include "../macros.h"
#include "helpers.h"

/**
 * @brief 
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool cleanAndCheckPrintStr(char* str)
{
    char* result = (char*)malloc(strlen(str)+1);
    int count = 0;
    int j = 0;

    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == PRINT_CHAR)
            count++;

        if (str[i] != '\n' && str[i] != PRINT_CHAR)
            result[j++] = str[i];
    }
    
    result[j] = '\0';

    strcpy(str, result);
    free(result);

    return (count == 2);
}

void check_for_tools()
{
    // do some checking to see if nasm and ld is installed and working

    int flag_for_nasm = system("nasm -v");

    #if (flag_for_nasm != 0)
        #error "NASM is currently needed for this compiler"
    #endif

    int flag_for_linker = system("ld -v");

    #if (flag_for_linker != 0)
        #error "LD is currently needed for this compiler"
    #endif

    system("cls");
}