all: main.o euler.o
	clang -o euler main.o euler.o

main.o: main.c euler.h
	clang -c main.c

euler.o: euler.c
	clang -c euler.c