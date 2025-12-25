

#include "helpers.h"

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

// TODO: Double check the logic behind the pointers on this one, \
    specifically the non-zero offset warning
char* create_new_name_for_output_file(
    char* file_name,
    char* file_new_extension
)
{
    char* file_output_name = (char*)malloc(sizeof(strlen(file_name)+5));

    char* ptr = strchr(file_name+2, '.');
    int index = -1;

    if (ptr)
    {
        index = ptr-(file_name+2);
        strncpy(file_output_name, file_name+2, index);
        file_output_name[index] = '\0';
        strcat(file_output_name, file_new_extension);
        return file_output_name;
    }
    free(file_output_name);
    free(ptr);
    return NULL;
};