// ----------------------------------------
// Author: Crash Sentinel
// 
// Purpose: Execute various different file operations 
// both general and in respects to the output file
//
// Current Date: 1/2/2026
// ----------------------------------------

#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <stdio.h>
#include "../codegen_context_params.h"
#include "../../lex/AST/AST_Node.c"

char* message_title = "msg";
char* length_title = "len";
static int emit_print_count = 0;
static int parse_print_count = 0;

#define BUFFER_LEN 1 << 8

/**
 * @brief - Opens a file and checks to see if it has opened successfully, 
 *          kills the program if unable to read from the file properly,
 *          which means that either the program file or creating the output file
 *          is failing somehow
 * 
 * @param file_name - The path for the file that you want to operate on
 * @param operation - The operator that you want to do on the file, same operators for fopen()
 * @return FILE* - the file that is safely open that you can now operate on
 */
FILE* open_file_and_check_nullity(
    char* file_name,
    char* operation
);

/**
 * @brief - Adds the general headers for the output nasm file to work with Windows x64 architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @note: See codegen_context_params.h for more details and functionality
 */
void write_windowsx64_headers(
    codegen_context_t* params
);

/**
 * @brief - Adds the general headers for the output nasm file to work with Linux Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_linux_headers(
    codegen_context_t* params
);

/**
 * @brief - Writes the NASM exit code at the end of the _main function
 *          to exit the program for Windows x64 architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_windowsx64_exit_code(
    codegen_context_t* params
);

/**
 * @brief - Writes the NASM exit code at the end of the _main function
 *          to exit the program for Linux Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_linux_exit_code(
    codegen_context_t* params
);

/**
 * @brief - Writes the section.data part of the program for the output file on Windows x64 Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_windowsx64_section_data(
    codegen_context_t* params
);

/**
 * @brief - Writes the SECTION .data part of the program for the output file on Linux Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_linux_section_data(
    codegen_context_t* params
);

/**
 * @brief - Writes the section.bss part of the program for the output file on Windows x64 Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_windowsx64_section_bss(
    codegen_context_t* params
);

/**
 * @brief - Writes the SECTION .bss part of the program for the output file on Linux Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_linux_section_bss(
    codegen_context_t* params
);

/**
 * @brief - Writes the section.text part of the program for the output file on Windows x64 Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_windowsx64_section_text(
    codegen_context_t* params
);

/**
 * @brief - Writes the SECTION .text part of the program for the output file on Linux Architecture
 * 
 * @param params - The typedef struct pointer of codegen_context_params to handle logic
 * @copydoc write_windowsx64_headers(codegen_context_t*)
 */
void write_linux_section_text(
    codegen_context_t* params
);

#endif // _FILE_OPS_H_