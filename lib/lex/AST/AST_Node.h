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


#endif // _AST_NODE_H_