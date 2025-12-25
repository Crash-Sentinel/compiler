
#include "parser.h"

void write_comment_node(
    FILE* file_to_write,
    ASTNode_t* node
)
{
    fprintf(file_to_write, "\n; %s\n", node->value);
}

// Should this have ASTNode_t* node for more expanded functionality?
void write_print_only_string_node(
    FILE* file_to_write
)
{
    char buff1[256];
    char buff2[256];

    sprintf(buff1, "%s%d", message_title, emit_print_count);
    sprintf(buff2, "%s%d", length_title, emit_print_count);

    fprintf(file_to_write, 
        "\tsub rsp, 40\n\n"
        "\tmov rcx, rbx\n"
        "\tlea rdx, [%s]\n"
        "\tmov r8d, %s\n"
        "\tlea r9, [written%d]\n"
        "\tmov qword [rsp+32], 0\n\n"
        "\tcall WriteConsoleA\n\n"
        "\tadd rsp, 40\n",
        buff1,
        buff2,
        emit_print_count
    );

    emit_print_count++;
}