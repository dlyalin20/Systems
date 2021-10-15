all: main.o structs.o
	clang -o structs main.o structs.o

main.o: main.c structs.h
	clang -c main.c

structs.o: structs.c
	clang -c structs.c

clean:
	rm *.o

run:
	./structs