
#include "AST/AST_Node.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_MAX_PER_LINE 1 << 8 // Arbitrary Large Size
#define COMMENT_CHAR	'$'
#define PRINT_CHAR	'"' 

// Updated check to make sure it's Windows x64
#if !defined(_WIN64)
    #error "Error: Windows x64 bit architecture is needed to compile"
#endif

int parse_print_count = 0;
int emit_print_count  = 0;
char* message_title = "msg";
char* length_title = "len";

_Bool cleanAndCheckPrintStr(char* str)
{
    char* result = (char*)malloc(strlen(str)+1);
    int count = 0;
    int j = 0;

    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == PRINT_CHAR)
            count++;

        if (str[i] != '\n' && str[i] != PRINT_CHAR)
            result[j++] = str[i];
    }
    
    result[j] = '\0';

    strcpy(str, result);
    free(result);

    return (count == 2);
}

int main(int argc, char** argv)
{
	
	if (argc > 3)
	{
		fprintf(stderr, "Insufficient arguments to compile");
		return -1;
	}

	FILE* f_read = fopen(argv[1], "r");

	if (f_read == NULL)
	{
		fprintf(stderr, "Unable to open file to compile");
		fclose(f_read);
		return -1;
	}

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

    FILE* f_write = fopen(file_output_name, "w");

    if (f_write == NULL)
    {
        fprintf(stderr, "Unable to open output file");
        return -1;
    }

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

    fprintf(f_write, "\nxor ecx, ecx\ncall ExitProcess\n");
	return 0;
}



