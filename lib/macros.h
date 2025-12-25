
#ifndef MACROS_H
#define MACROS_H

#include <stdlib.h>
#include <stdio.h>
#include "./tools/codegen_context_params.h"

#define CHAR_MAX_PER_LINE 1 << 8 // Arbitrary Large Size
#define COMMENT_CHAR	  '$'
#define PRINT_CHAR	      '"'

// int parse_print_count = 0;
// int emit_print_count  = 0;

// #define BEHAVIOR 0 // SET TO 0 BY DEFAULT / FULLY COMPILES A PE BY DEFAULT

#define _ASM_ONLY_FLAG_ "-nasm"
// #define _ASM_LINK_CREATE_PE_FLAG_ "-pe"


// Ensuring correct functions are used for different OS types
#if defined(__linux__)

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

#else
    #error "Unknown OS detected, cannot compile"
#endif


#endif // _MACROS_H_