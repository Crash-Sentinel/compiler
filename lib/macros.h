// ----------------------------------------
// Author: Crash Sentinel
// 
// Purpose: Define Macros and function abstractions depending on the OS version that is currently
// being used by the specific user.
//
// Current Date: 1/2/2026
// ----------------------------------------

#ifndef MACROS_H
#define MACROS_H

#include <stdlib.h>
#include <stdio.h>
#include "./tools/codegen_context_params.h"
#include "./parse/parser.h"

// Macros
#define CHAR_MAX_PER_LINE 1 << 8 // Arbitrary Large Size
#define COMMENT_CHAR	  '$'
#define PRINT_CHAR	      '"'

// Flags for Compilation (-- Unused but will be soon --)
#define _ASM_ONLY_FLAG_ "-nasm"

// Define Abstract Functions to define OS specific behavior for the Lexer / Parser to interpret
#if defined(__linux__)
    // Linux Distros

    void write_headers(
        codegen_context_t* params
    ) { write_linux_headers(params); }

    void write_exit_code(
        codegen_context_t* params
    ) { write_linux_exit_code(params); }

    void write_section_data(
        codegen_context_t* params
    ) { write_linux_section_data(params); }

    void write_section_bss(
        codegen_context_t* params
    ) { write_linux_section_bss(params); }

    void write_section_text(
        codegen_context_t* params
    ) { write_linux_section_text(params); }

    void write_print_only_string_node(
        FILE* file_to_write
    ) { write_linux_print_only_string_node(file_to_write); }

    // 64 architecture Windows
#elif defined(_WIN64)

    void write_headers(
        codegen_context_t* params
    ) { write_windowsx64_headers(params); }

    void write_exit_code(
        codegen_context_t* params
    ) { write_windowsx64_exit_code(params); }

    void write_section_data(
        codegen_context_t* params
    ) { write_windowsx64_section_data(params); }

    void write_section_bss(
        codegen_context_t* params
    ) { write_windowsx64_section_bss(params); }

    void write_section_text(
        codegen_context_t* params
    ) { write_windowsx64_section_text(params); }

    void write_print_only_string_node(
        FILE* file_to_write
    ) { write_windowsx64_print_only_string_node(file_to_write); }

// Expect _WIN32 possibilities in the future 

#else
    #error "Unknown OS detected, cannot compile"
#endif


#endif // _MACROS_H_