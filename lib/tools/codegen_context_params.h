#ifndef CODEGEN_CONTEXT_H
#define CODEGEN_CONTEXT_H

#include "../lex/AST/AST_Node.h"
#include <stdio.h>

typedef struct {
    FILE* file_to_write;
    ASTNode_t* program;
    int size_of_program;
} codegen_context_t;

#endif // CODEGEN_CONTEXT_H