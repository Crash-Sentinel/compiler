#ifndef LEX_H
#define LEX_H

#include <string.h>

/**
 * @brief Create a Comment Node for the AST
 * 
 * @param buffer - the raw buffer 
 * @param program_size - the program size (this will typically always be a reference to the program_size, so "&program_size")
 */
void addCommentNode(
    char* buffer,
    ASTNode_t* program,
    int* program_size
);

/**
 * @brief - Appends a Print Node specifically for only string values, 
 *          something like "Hello World!" rather than "My variable: {var}"
 * 
 * @copydoc addCommentNode
 * @param buffer - The raw buffer string
 * @param program - a pointer to the program (this will also just be a reference to the program in AST_Node.c)
 * @param program_size - the program size (this will typically always be a reference to the program_size, so "&program_size")
 */
void addPrintOnlyString(
    char* buffer,
    ASTNode_t* program,
    int* program_size
);

#endif // _LEX_H_