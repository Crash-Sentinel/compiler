// ----------------------------------------
// Author: Crash Sentinel
// 
// Purpose: Helper functions to do some smaller logic without being related to 
// the lexer, parser, or other related compiler logic
//
// Current Date: 1/2/2026
// ----------------------------------------

#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>
#include <string.h>

#include "../macros.h"

/**
 * @brief - Takes the raw string for a print statement (something like "Hello World!")
 *          and then transforms that into (Hello World!) to then be stored into an ASTNode.
 *
 *          Also does some semantic checks to ensure that the string is closed, meaning it's like ("Hello World!")
 *          and not like ("Hello World!)
 * 
 * @param str - The raw string to check and validate
 * @return bool - (1) if a valid string, (0) if not a valid string
 */
bool cleanAndCheckPrintStr(char* str);

/**
 * @brief - Checks to see if NASM and the LD assembler and linker are on the system
 *
 * @note: This may be changed to let users just get the assembly code instead of assembling and linking the code
 *        through the ACC
 */
void check_for_tools();

/**
 * @brief - Creates a default filename for assembly based on the program file name, basically yourProgram.txt 
 *          gets turned into yourProgram.asm or what file_new_extension may be
 * 
 * @param file_name - Your program's file name
 * @param file_new_extension - The extension that you want the new file to have
 * @return (char*) the new output file for acc to then create and build off of
 *
 * @note: This may be changed based on how the flags might work in the future, allowing the user to type in
 *        their own output file names like how you can do for GCC
 */
char* create_new_name_for_output_file(
    char* file_name,
    char* file_new_extension
);

#endif