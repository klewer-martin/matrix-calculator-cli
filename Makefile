CC = gcc
FLAGS = -Wall -pedantic

all: clean prompt.o matrix.o main.o
	$(CC) $(FLAGS) main.o matrix.o prompt.o

matrix.o: status.h matrix.h
	$(CC) $(FLAGS) -c matrix.c

prompt.o:
	$(CC) $(FLAGS) -c prompt.c

main.o:
	$(CC) $(FLAGS) -c main.c

clean:
	rm -rf *.o
