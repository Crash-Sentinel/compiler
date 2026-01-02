// ----------------------------------------
// Author: Bennett Miller
//
// Purpose: The main.c file that makes everything run + will be then compiled (yes, compiling a compiler)
// to get the executable that can actually do compiling of your program
// 
// Date: 1/2/2026
// ----------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex/AST/AST_Node.c"
#include "../lib/tools/codegen_context_params.h"
#include "tools/file_ops/file_ops.c"
#include "macros.h"
#include "tools/helpers.c"
#include "lex/lex.c"
#include "parse/parser.c"

// Comment this line to disable debug mode:
#define DEBUG_MODE 1

#if defined(DEBUG_MODE)
    bool debug_mode_flag = 1;
#else
    bool debug_mode_flag = 0;
#endif

int main(int argc, char** argv)
{
    check_for_tools();

	if (argc < 2)
	{
		fprintf(stderr, "Insufficient arguments to compile");
		return -1;
	}

    FILE* f_read = open_file_and_check_nullity(
        argv[1],
        "r"
    );

	char buffer[CHAR_MAX_PER_LINE];

    // This could be refactored
	while (fgets(buffer, sizeof(buffer), f_read) != NULL)
	{
        if (debug_mode_flag)
            printf("Program size: %d\n", program_size);
        
        char* copyOfBuffer = (char*)malloc(strlen(buffer)+1);
        strcpy(copyOfBuffer, buffer);

		if (buffer[0] == COMMENT_CHAR)
		{
            if (debug_mode_flag)
                printf("Comment made\n");
            append_comment_node_to_ast(
                buffer,
                program,
                &program_size
            );
            continue;
		}
		
        if (cleanAndCheckPrintStr(copyOfBuffer))
		{
            if (debug_mode_flag)
                printf("Print Only Added\n");
            addPrintOnlyString(copyOfBuffer, program, &program_size);
            continue;
		}  
	}

    char* file_output_name = create_new_name_for_output_file(argv[1], ".asm");
    if (debug_mode_flag)
    {        
        printf("%s\n", argv[1]);
        printf("%s\n", file_output_name);
    }

    FILE* f_write = open_file_and_check_nullity(
        file_output_name,
        "w"
    );

    if (f_write == NULL)
    {
        fprintf(stderr, "Error: Unable to open file correctly!\n");
        exit(-1);
    }

    codegen_context_t params = {
        .file_to_write = f_write,
        .program = program,
        .size_of_program = program_size
    };

    write_headers(
        &params
    );

    write_section_data(
        &params
    );

    write_section_bss(
        &params
    );

    write_section_text(
        &params
    );

    for (int i = 0; i < program_size; i++)
    {
        ASTNode_t current_node = program[i];

        if (current_node.type == NODE_COMMENT)
            write_comment_node(f_write, &current_node);

        if (current_node.type == NODE_PRINT)
            write_print_only_string_node(f_write);
    }
	
    write_exit_code(
        &params
    );

    fclose(f_write);
    
    return 0;
}



