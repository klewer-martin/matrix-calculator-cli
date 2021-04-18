CC = gcc
FLAGS = -Wall -pedantic

all: clean main.o matrix_struct.o
	$(CC) $(FLAGS) main.o matrix_struct.o

main.o:
	$(CC) $(FLAGS) -c main.c

matrix_struct.o:
	$(CC) $(FLAGS) -c matrix_struct.c

clean:
	rm -rf *.o
