CC = gcc
CFLAGS = -g
objects = linked.o test.o
TARGET = linked_test

$(TARGET): $(objects)
	$(CC) -o $@ $(objects)

linked.o : linked.c
	$(CC) -c -o linked.o linked.c

test.o: test.c
	$(CC) -c -o test.o test.c 

clean:
	rm $(objects)

