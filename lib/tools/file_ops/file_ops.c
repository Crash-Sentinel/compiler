#include "file_ops.h"
#include <stdlib.h>

FILE* open_file_and_check_nullity(
    char* file_name,
    char* operation
)
{
    FILE* f_read = fopen(file_name, operation);

    if (f_read == NULL)
    {
        fprintf(stderr, "Unable to open file: %s\n", file_name);
        exit(-1);
    }
    return f_read;
};

void write_windowsx64_exit_code(
    codegen_context_t* params
)
{
    if (params->file_to_write == NULL)
        fprintf(stderr, "NULL File detected");
    else
        fprintf(params->file_to_write, "\nxor ecx, ecx\ncall ExitProcess\n" );
}

// TODO: Finish this
void write_linux_exit_code(
    codegen_context_t* params
)
{

}

void write_windowx64_headers(
    codegen_context_t* params
)
{
    fprintf(params->file_to_write, "default rel\nextern GetStdHandle\nextern WriteConsoleA\nextern ExitProcess\n\n");
}

// TODO: Finish this
void write_linux_headers(
    codegen_context_t* params
)
{

}

void write_windowsx64_section_data(
    codegen_context_t* params
)
{
    
    ASTNode_t* program = params->program;

    fprintf(params->file_to_write, "section .data\n");
    for (int i = 0; i < params->program_size; ++i)
    {
        ASTNode_t node = program[i];
        if (node.type == NODE_PRINT)
        {
            char buffer[256];
            char buffer2[256];

            sprintf(buffer, "%s%d", message_title, emit_print_count);
            sprintf(buffer2, "%s%d", length_title, emit_print_count);

            emit_print_count++;

            fprintf(params->file_to_write,
                "\t%s db \"%s\", 10\n"
                "\t%s equ $ - %s\n",
                buffer,
                node.value,
                buffer2,
                buffer
            );
        }
    }

    free(program);
}

// TODO: Finish this
void write_linux_section_data(
    codegen_context_t* params
)
{

}

void write_windowsx64_section_bss(
    codegen_context_t* params
)
{
    ASTNode_t* program = params->program;

    fprintf(params->file_to_write, "\nsection .bss\n");
    for (int i = 0; i < params->program_size; ++i)
    {
        ASTNode_t currentNode = program[i];
        if (currentNode.type == NODE_PRINT)
        {
            char buffer[256];

            sprintf(
                buffer,
                "\t%s%d resd 1",
                "written",
                emit_print_count
            );

            fprintf(params->file_to_write, "%s\n", buffer);
            emit_print_count++;
        }
    }

    free(program);
}

// TODO: Finish This
void write_linux_section_bss(
    // FILE* file_to_write,
    // ASTNode_t* program,
    // int program_size
    codegen_context_t* params
)
{}

void write_windowsx64_section_text(
    codegen_context_t* params
)
{
    fprintf(params->file_to_write,
        "\nsection .text\n"
        "\tglobal main\n"
        "main:\n"
        "\tmov ecx, -11\n"
        "\tcall GetStdHandle\n"
        "\tmov rbx, rax\n"
    );

    emit_print_count = 0;
}

// TODO: Finish This
void write_linux_section_text(
    // FILE* file_to_write,
    // ASTNode_t* program,
    // int program_size
    codegen_context_t* params
)
{}

