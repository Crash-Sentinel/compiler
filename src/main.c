
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

	if (argc < 2) // Updated this to the correct amount of arguments I want 
	{
		fprintf(stderr, "Insufficient arguments to compile");
		return -1;
	}

    FILE* f_read = open_file_and_check_nullity(
        argv[1],
        "r"
    );

	char buffer[CHAR_MAX_PER_LINE];

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
        {
            // fprintf(f_write, "\n; %s\n", current_node.value);

            write_comment_node(f_write, &current_node);
        }

        if (current_node.type == NODE_PRINT)
        {
            write_print_only_string_node(f_write);
        }
    }
	
    // write_exit_code(f_write);
    write_exit_code(
        &params
    );

    fclose(f_write);

    // if (_ASM_LINK_CREATE_PE_FLAG_)
    // {
    //     char* message_one = (char*)malloc(sizeof(char*));
    //     snprintf(message_one, sizeof(message_one), "nasm -f win64 %s.asm -o %s.o", file_output_name);

    //     int first_call = system(message_one);

    //     if (first_call != 0)
    //     {
    //         fprintf(stderr, "Error: Something went wrong with the nasm assembly in the compilation process");
    //         free (message_one);
    //         return -1;
    //     } else {
    //         char* message_two = (char*)malloc(sizeof(char*));
    //         snprintf(message_two, sizeof(message_two), "ld %s.o -o %s.exe -lkernel32 -e main", file_output_name);

    //         int final_call = system(message_two);

    //         if (final_call != 0)
    //         {
    //             fprintf(stderr, "Error: Something went wrong with the ld linker in the compilation process");
    //             free (message_two);
    //             return -1;
    //         }
    //     }
    // }
    
    return 0;
}



