#include <stdlib.h>

#ifndef _MACROS_H_
#define _MACROS_H_

#define CHAR_MAX_PER_LINE 1 << 8 // Arbitrary Large Size
#define COMMENT_CHAR	'$'
#define PRINT_CHAR	'"'

#define BEHAVIOR 0 // SET TO 0 BY DEFAULT / FULLY COMPILES A PE BY DEFAULT

#define _ASM_ONLY_FLAG_ "-nasm"
#define _ASM_LINK_CREATE_PE_FLAG_ "-pe"

// wrong
// // 0 meaning true, 1 meaning false here
// #if BEHAVIOR == 0
//     #define _ASM_LINK_CREATE_PE_FLAG_ 1
//     #define _ASM_ONLY_ACTIV_ 0
// #elif BEHAVIOR == 1
//     #define _ASM_LINK_CREATE_PE_FLAG 0
//     #define _ASM_ONLY_ACTIV_ 1
// #endif


#endif // _MACROS_H_