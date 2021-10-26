all: main.o random.o
	clang -o random main.o random.o

main.o: main.c random.h
	clang -c main.c

random.o: random.c
	clang -c random.c

clean:
	rm -rf *.o *.out

run: 
	./random