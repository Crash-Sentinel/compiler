
#include "lex.h"

void append_comment_node_to_ast(
    char* buffer,
    ASTNode_t* program,
    int* program_size
)
{
    char value[256];
    int new_size = strlen(buffer)-1;

    if (new_size > CHAR_MAX_PER_LINE-1)
        new_size = CHAR_MAX_PER_LINE-1;

    strncpy(value, buffer+1, new_size);
    value[new_size] = '\0';

    ASTNode_t comment_node = {
        .type = NODE_COMMENT,
        .value = strdup(value),
    };

    program[(*program_size)] = comment_node;
    (*program_size) = (*program_size) + 1;
}

void addPrintOnlyString(
    char* buffer,
    ASTNode_t* program,
    int* program_size
)
{
    parse_print_count++;
    
    ASTNode_t print_node = {
        .type = NODE_PRINT,
        .value = strdup(buffer)
    };

    program[(*program_size)] = print_node;
    (*program_size) = (*program_size) + 1;
}