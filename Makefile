CC = gcc
CFLAGS = -g
SRC = linked.c test.c
objects = linked.o test.o
TARGET = linked_test

$(TARGET): $(objects)
	$(CC) -o $@ $(objects)

linked.o: linked.c
	$(CC) $(CFLAGS) -c -o $@ $<

test.o: test.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(objects) $(TARGET)

