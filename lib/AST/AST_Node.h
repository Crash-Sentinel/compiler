#ifndef _AST_NODE_H_
#define _AST_NODE_H_

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