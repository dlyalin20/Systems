all: main.o arrays.o
	clang -o main main.o arrays.o

main.o: main.c arrays.h
	clang -c main.c

arrays.o: arrays.c
	clang -c arrays.c

clean:
	rm *.o