
#ifndef FILE_OPS_H
#define FILE_OPS_H

#include <stdio.h>
#include "../codegen_context_params.h"

char* message_title = "msg";
char* length_title = "len";
static int emit_print_count = 0;
static int parse_print_count = 0;

/**
 * @brief - TODO: Finish This
 * 
 * @param file_name - TODO: Finish This
 * @param operation - TODO: Finish This
 * @return FILE* - TODO: Finish This
 */
FILE* open_file_and_check_nullity(
    char* file_name,
    char* operation
);

/**
 * @brief - TODO: Finish This
 * 
 * @param file_to_write - TODO: Finish This
 */
void write_windowsx64_headers(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_linux_headers(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param file_to_write - TODO: Finish This
 */
void write_windowsx64_exit_code(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_linux_exit_code(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: FINISH THIS
 */
void write_windowsx64_headers(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_linux_headers(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_windowsx64_section_data(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_linux_section_data(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_windowsx64_section_bss(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_linux_section_bss(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_windowsx64_section_text(
    codegen_context_t* params
);

/**
 * @brief - TODO: Finish This
 * 
 * @param params - TODO: Finish This
 */
void write_linux_section_text(
    codegen_context_t* params
);

#endif // _FILE_OPS_H_