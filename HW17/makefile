all: user.o controller.o 
	clang -o user user.o
	clang -o controller controller.o

controller.o: controller.c controller.h 
	clang -c controller.c

user.o: user.c user.h 
	clang -c user.c 

clean:
	rm -rf *.o *.txt