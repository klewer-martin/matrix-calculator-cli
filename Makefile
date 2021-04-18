CC = gcc
FLAGS = -Wall -pedantic

all: clean main.o matrix.o
	$(CC) $(FLAGS) main.o matrix.o

main.o:
	$(CC) $(FLAGS) -c main.c

matrix.o:
	$(CC) $(FLAGS) -c matrix.c

clean:
	rm -rf *.o
