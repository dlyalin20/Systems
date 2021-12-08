all: main.o
	clang -o main main.o

main.o: main.c main.h
	clang -c main.c 

clean:
	rm -rf *.o

run:
	./main