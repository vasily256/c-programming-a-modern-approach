findcode: findcode.o codes.o
	gcc -o findcode findcode.o codes.o

findcode.o: findcode.c codes.h
	gcc -c findcode.c

codes.o: codes.c codes.h
	gcc -c codes.c
