
#include <stdio.h>
#include "../AST/AST_Node.h"

#ifndef _FILE_OPS_H_
#define _FILE_OPS_H_

/**
 * @brief 
 * 
 * @param file_name 
 * @param operation 
 * @return FILE* 
 */
FILE* open_file_and_check_nullity(
    char* file_name,
    char* operation
);

// Write headers for the assembly code
/**
 * @brief 
 * 
 * @param file_to_write 
 * @param program 
 * @param program_size 
 */
void write_headers(
    FILE* file_to_write,
    ASTNode_t* program,
    int program_size
);

// Write the section.data 
/**
 * @brief 
 * 
 * @param file_to_write 
 * @param program 
 * @param program_size 
 */
void write_section_data(
    FILE* file_to_write,
    ASTNode_t* program,
    int program_size
);

// Write the section.bss 
/**
 * @brief 
 * 
 * @param file_to_write 
 * @param program 
 * @param program_size 
 */
void write_section_bss(
    FILE* file_to_write,
    ASTNode_t* program,
    int program_size
);

// Write the section.text
/**
 * @brief 
 * 
 * @param file_to_write 
 * @param program 
 * @param program_size 
 */
void write_section_text(
    FILE* file_to_write,
    ASTNode_t* program,
    int program_size
);

// Write the exit code
/**
 * @brief 
 * 
 * @param file_to_write 
 */
void write_exit_code(
    FILE* file_to_write
);

#endif // _FILE_OPS_H_