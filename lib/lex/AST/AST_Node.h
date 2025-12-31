#ifndef AST_NODE_H
#define AST_NODE_H

/**
 * @brief 
 * 
 */
typedef enum {
    NODE_COMMENT,
    NODE_PRINT
} NodeType;

/**
 * @brief 
 * 
 */
typedef struct ASTNode
{
    NodeType type;
    char* value;
} ASTNode_t;

static int program_size = 0;    //depth


#endif // _AST_NODE_H_