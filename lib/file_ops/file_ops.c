#include "file_ops.h"
#include "macros.h"

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

void write_exit_code(
    FILE* file_to_write
)
{
    if (file_to_write == NULL)
    {
        fprintf(stderr, "Null point here");
    }

    #if defined(_WIN64)
        fprintf(
            file_to_write,
            "\nxor ecx, ecx\ncall ExitProcess\n"
        );
    #elif defined(__linux__)
        // logic
    #else
        #error "Unsupported platform!"
    #endif
    
};