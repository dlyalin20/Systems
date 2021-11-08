all: csv.o main.o
	clang -o csv main.o csv.o

csv.o: csv.c csv.h
	clang -c csv.c

main.o: main.c
	clang -c main.c

clean:
	rm -rf *.o

test:
	./csv read_csv
	echo -e "\n"
	./csv read_data
	echo -e "\n"
	./csv add_data
	echo -e "\n"
	./csv update_data
