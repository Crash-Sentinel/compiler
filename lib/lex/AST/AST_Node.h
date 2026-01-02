#ifndef AST_NODE_H
#define AST_NODE_H

/**
 * @brief 
 * Showcases the types of NodeTypes that will then make up the AST to then process
 */
typedef enum {
    NODE_COMMENT,
    NODE_PRINT
} NodeType;

/**
 * @brief 
 * Basic typedef struct showcasing a ASTNode
 */
typedef struct ASTNode
{
    NodeType type;
    char* value;
} ASTNode_t;

// (depth): "global" variable to show the depth of the AST tree
static int program_size = 0;    

#endif // _AST_NODE_H_