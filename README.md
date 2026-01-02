## INFO

This is a test compiler made for Aidan, for a custom Language 
which I called Aidanic (but could change if he doesn't like it)

Still isn't fully developed and there's a lot that I want to fix with it.
But I wanted to deliver something before Christmas so I had something to show for it.

Merry Christmas!

NOTE: This version only currently works on Windows 64 architecture, sorry, I'm working on it.

NOTE 2: The assembly file is written not only in respect to Windows 64 architecture, but works mainly with the NASM assembler as well. I haven't tested other assemblers but I recommend using NASM because it's what I used personally

P.S. Making the main.exe executable from your terminal is recommended (so that you can run it from any directory!)

## Tree

```
readme
│   
├───.vscode
│       launch.json
│       tasks.json
│       
├───bin
│       acc.bat
│       main.exe
│
├───doc
├───lib
│   └───AST
│           AST_Node.c
│           AST_Node.h
│
└───src
        main.c
        makefile
        test.txt
```

## Ideal Final Example Program

```
$ Comment here

$ Function
def sum(I16 a, I16 b):
    return a + b

$ Main Function
def main(void):
    $ Variable initialization and main function isn't a def
    U8 x = 5
    U8 y = 10

    $ Quotation marks mean print string, the {} show actual values
    "Result: {sum(x,y)}"
```

Datatypes for Future Variables and their C equivalent
`U8` uint8_t
`U16` uint16_t
`U32` uint32_t
`U64` uint64_t

`I8` int8_t
`I16` int16_t
`I32` int32_t
`I64` int64_t

Although it only compiles in .txt files for now, if possible, I want to make my own 
file extension for Aidanic, something like .aic would be cool

## Current Working Example Program

Only comments and fully string printing as of 12.11.2025

```
$ This is a comment

$ This prints Hello World! -> similar to print("Hello World!")
"Hello World!"
```

## Using NASM and ld to create a PE

Replace `FILE_NAME` with your assembly file name, it should be the same name as your text file

```
nasm -f win64 {FILE_NAME}.asm -o {FILE_NAME}.o
ld {FILE_NAME}.o -o {FILE_NAME}.exe -lkernel32 -e main
```

## Update Log Details

1/2/2026: Happy 2026 new year! With it brings Arch and possibly Linux OS capabilities for the 
acc compiler! More testing is needed on my part to ensure it's all Linux Distros but overall good steps
for the "I use Arch BTW" fiends (including myself)

Hopefully I fixed the readme to actually work right in Github, and my documentation is much more cleaner (...Hopefully)

Still looking towards making variables, but there are also things that I want to refactor or just update excluding
the things that need that more higher level functionality. In either case, hope you enjoy!