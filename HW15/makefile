all: parse.o main.o
	clang -o parse main.o parse.o

parse.o: parse.c parse.h
	clang -c parse.c

main.o: main.c
	clang -c main.c

clean:
	rm -rf *.o

run:
	./parse