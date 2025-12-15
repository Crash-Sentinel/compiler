
FILE_NAME := test

compile:
	nasm -f win64 ${FILE_NAME}.asm -o ${FILE_NAME}.o
	ld ${FILE_NAME}.o -o ${FILE_NAME}.exe -lkernel32 -e main

clean:
	rm -rf ${FILE_NAME}.o
	rm -rf ${FILE_NAME}.asm
	rm -rf ${FILE_NAME}.exe

try:
	gcc -I ../lib/ ./main.c -o ../bin/main.exe
	../bin/main.exe ./${FILE_NAME}.txt
	make compile