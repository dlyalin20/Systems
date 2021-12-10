all: interface worker

interface: interface.o
	clang -o interface interface.o

interface.o: interface.c interface.h
	clang -c interface.c 

worker: worker.o
	clang -o worker worker.c

worker.o: worker.c worker.h
	clang -c worker.c

clean:
	rm -rf *.o