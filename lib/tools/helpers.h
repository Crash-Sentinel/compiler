
#include <stdbool.h>

#ifndef _HELPERS_H_
#define _HELPERS_H_

/**
 * @brief 
 * 
 * @param str 
 * @return bool (<= (equivalent to) => _Bool) 
 */
bool cleanAndCheckPrintStr(char* str);

/**
 * @brief Checks to see if NASM and the LD assembler and linker are on the system
 * 
 */
void check_for_tools();

#endif