
#include "AST/AST_Node.c"
#include "macros.h"
#include "file_ops/file_ops.c"
#include "tools/helpers.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Updated check to make sure it's Windows x64
// Will add reliability against different OS's soon
#if !defined(_WIN64)
    #error "Error: Windows x64 bit architecture is needed to compile"
#endif

int parse_print_count = 0;
int emit_print_count  = 0;
char* message_title = "msg";
char* length_title = "len";


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
        char* copyOfBuffer = (char*)malloc(strlen(buffer)+1);
        strcpy(copyOfBuffer, buffer);

		if (buffer[0] == COMMENT_CHAR)
		{
			char value[256];
			int new_size = strlen(buffer)-1;

            if (new_size > CHAR_MAX_PER_LINE-1)
                new_size = CHAR_MAX_PER_LINE-1;

			strncpy(value, buffer+1, new_size);
			value[new_size] = '\0';

			ASTNode_t comment_node = {
				.type = NODE_COMMENT,
				.value = strdup(value),
			};

			program[program_size++] = comment_node;
            continue;
		}
		
        if (cleanAndCheckPrintStr(copyOfBuffer))
		{
            parse_print_count++;
			
			ASTNode_t print_node = {
				.type = NODE_PRINT,
                .value = strdup(copyOfBuffer)
			};

			program[program_size++] = print_node;
            continue;
		}
	}

    char* file_output_name = (char*)malloc(strlen(argv[1])+5);
    
    int len = strlen(argv[1]) - 4;
    strncpy(file_output_name, argv[1], len);
    file_output_name[len] = '\0';

    file_output_name = strcat(file_output_name, ".asm");

    FILE* f_write = open_file_and_check_nullity(
        file_output_name,
        "w"
    );

    fprintf(f_write, "default rel\nextern GetStdHandle\nextern WriteConsoleA\nextern ExitProcess\n\n");

    fprintf(f_write, "section .data\n");
    for (int i = 0; i < program_size; ++i)
    {
        ASTNode_t node = program[i];
        if (node.type == NODE_PRINT)
        {
            char buffer[256];
            char buffer2[256];

            sprintf(buffer, "%s%d", message_title, emit_print_count);
            sprintf(buffer2, "%s%d", length_title, emit_print_count);

            emit_print_count++;

            fprintf(f_write,
                "\t%s db \"%s\", 10\n"
                "\t%s equ $ - %s\n",
                buffer,
                node.value,
                buffer2,
                buffer
            );
        }
    }

    emit_print_count = 0;

    fprintf(f_write, "\nsection .bss\n");
    for (int i = 0; i < program_size; ++i)
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

            fprintf(f_write, "%s\n", buffer);
            emit_print_count++;
        }
    }

    fprintf(f_write,
        "\nsection .text\n"
        "\tglobal main\n"
        "main:\n"
        "\tmov ecx, -11\n"
        "\tcall GetStdHandle\n"
        "\tmov rbx, rax\n"
    );

    emit_print_count = 0;

    for (int i = 0; i < program_size; i++)
    {
        ASTNode_t current_node = program[i];

        if (current_node.type == NODE_COMMENT)
        {
            fprintf(f_write, "\n; %s\n", current_node.value);
        }

        if (current_node.type == NODE_PRINT)
        {
            char buff1[256];
            char buff2[256];

            sprintf(buff1, "%s%d", message_title, emit_print_count);
            sprintf(buff2, "%s%d", length_title, emit_print_count);

            fprintf(f_write, 
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
    }

    // fprintf(f_write, "\nxor ecx, ecx\ncall ExitProcess\n");
	
    write_exit_code(f_write);

    fclose(f_write);

    // new work

    if (_ASM_LINK_CREATE_PE_FLAG_)
    {

        //nasm -f win64 ${FILE_NAME}.asm -o ${FILE_NAME}.o
	// ld ${FILE_NAME}.o -o ${FILE_NAME}.exe -lkernel32 -e main
        // system("nasm -f win64 ")
        char* message_one = (char*)malloc(sizeof(char*));
        snprintf(message_one, sizeof(message_one), "nasm -f win64 %s.asm -o %s.o", file_output_name);

        int first_call = system(message_one);

        if (first_call != 0)
        {
            fprintf(stderr, "Error: Something went wrong with the nasm assembly in the compilation process");
            free (message_one);
            return -1;
        } else {
            char* message_two = (char*)malloc(sizeof(char*));
            snprintf(message_two, sizeof(message_two), "ld %s.o -o %s.exe -lkernel32 -e main", file_output_name);

            int final_call = system(message_two);

            if (final_call != 0)
            {
                fprintf(stderr, "Error: Something went wrong with the ld linker in the compilation process");
                free (message_two);
                return -1;
            }
        }
    }
    
    return 0;
}



