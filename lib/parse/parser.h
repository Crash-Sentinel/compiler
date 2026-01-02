// ----------------------------------------
// Author: Crash Sentinel
// 
// Purpose: Writes into the output file to based on the operating system 
// and the node passed
//
// Current Date: 1/2/2026
// ----------------------------------------

#ifndef PARSER_H
#define PARSER_H

/**
 * @brief - Writes the structure for a comment node to the file 
 * 
 * @param file_to_write - The File that you want to write to
 * @param node - The specific comment node
 */
void write_comment_node(
    FILE* file_to_write,
    ASTNode_t* node
);

/**
 * @brief - Writes the structure for a Print String Only node for Windows x64 Architecture
 * @note - The logic behind this doesn't specifically require the node, instead it generates
 *         the literal "msg_#" where # is the specific iteration of the message
 * 
 * @param file_to_write - The File that you want to write to
 */
void write_windowsx64_print_only_string_node(
    FILE* file_to_write
);

/**
 * @brief - Writes the structure for a Print String Only node but for Linux Architecture
 * @copydoc write_windowsx64_print_only_string_node 
 *
 * @param file_to_write - The File that you want to write to
 */
void write_linux_print_only_string_node(
    FILE* file_to_write
);

#endif // _PARSER_H_