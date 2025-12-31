#ifndef LEX_H
#define LEX_H

#include <string.h>

/**
 * @brief Create a Comment Node for the AST
 * 
 * @param buffer - TODO: Finish This 
 * @param program_size - TODO: Finish This 
 */
void addCommentNode(
    char* buffer,
    ASTNode_t* program,
    int* program_size
);

/**
 * @brief - TODO: Finish This
 * 
 * @param buffer - TODO: Finish This 
 * @param program - TODO: Finish This 
 * @param program_size - TODO: Finish This 
 */
void addPrintOnlyString(
    char* buffer,
    ASTNode_t* program,
    int* program_size
);

#endif // _LEX_H_