CC = gcc 
CFLAGS = -std=c99 -Wall -pedantic

all: run 

clean: 
	rm *.o run

run: country.h main.o country.o 
	$(CC) $(CFLAGS) main.o country.o -o run 

main.o: country.h main.c 
	$(CC) $(CFLAGS) -c main.c -o main.o 

country.o: country.h country.c 
	$(CC) $(CFLAGS) -c country.c -o country.o 