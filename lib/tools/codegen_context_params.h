// ----------------------------------------
// Author: Crash Sentinel
// 
// Purpose: Defines a typedef struct for passing params to the lexer, parser, and other functions without having
// to redefine the same params each time. 
//
// Current Date: 1/2/2026
// ----------------------------------------

#ifndef CODEGEN_CONTEXT_H
#define CODEGEN_CONTEXT_H

#include "../lex/AST/AST_Node.h"
#include <stdio.h>

/**
 * @brief This is the basic typedef struct "codegen_context_t" that will be passed to
 *        file_ops.h or macros.h
 */
typedef struct {
    FILE* file_to_write;
    ASTNode_t* program;
    int size_of_program;
} codegen_context_t;

#endif // CODEGEN_CONTEXT_H