all: main.o strings.o
	clang -o strings main.o strings.o

main.o: main.c strings.h
	clang -c main.c

strings.o: strings.c
	clang -c strings.c

clean:
	rm *.o

run:
	./strings
