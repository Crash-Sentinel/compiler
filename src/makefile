
FILE_NAME := test

compile_win:
	nasm -f win64 ${FILE_NAME}.asm -o ${FILE_NAME}.o
	ld ${FILE_NAME}.o -o ${FILE_NAME}.exe -lkernel32 -e main

clean:
	rm -rf ${FILE_NAME}.o
	rm -rf ${FILE_NAME}.asm
	rm -rf ${FILE_NAME}.exe
	rm -rf ${FILE_NAME}

try_win:
	gcc -I ../lib/ ./main.c -o ../bin/main.exe
	../bin/main.exe ./${FILE_NAME}.txt
	make compile_win

try_linux:
	gcc -I ../lib/ ./main.c -o ../bin/main.exe
	../bin/main.exe ./${FILE_NAME}.txt
	make compile_linux

compile_linux:
	nasm -f elf64 ./${FILE_NAME}.asm -o ./${FILE_NAME}.o
	ld ./${FILE_NAME}.o -o ./${FILE_NAME}