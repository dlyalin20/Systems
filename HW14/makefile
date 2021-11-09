all: main.o
	clang -o sigs main.o

main.o: main.c headers.h
	clang -c main.c

clean:
	rm -rf *.o

run:
	./sigs