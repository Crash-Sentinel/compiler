
#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>
#include <string.h>

#include "../macros.h"

/**
 * @brief - TODO: Finish This
 * 
 * @param str - TODO: Finish This 
 * @return bool - TODO: Finish This
 */
bool cleanAndCheckPrintStr(char* str);

/**
 * @brief Checks to see if NASM and the LD assembler and linker are on the system
 */
void check_for_tools();

/**
 * @brief - TODO: Finish This 
 * 
 * @param file_name - TODO: Finish This
 * @param file_new_extension - TODO: Finish This
 * @return (char*) the new output file for acc to then create and build off of
 */
char* create_new_name_for_output_file(
    char* file_name,
    char* file_new_extension
);

#endif