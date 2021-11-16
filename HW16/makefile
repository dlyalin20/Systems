all: main.o
	clang -o child main.c

main.o: main.c headers.h
	clang -c main.c 

clean:
	rm -rf *.o

run:
	./child