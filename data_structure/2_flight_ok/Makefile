CC = gcc
CFLAGS = -g -Wall -O0

flight:main.c menu.c flight.c
	$(CC) $(CFLAGS)  -o $@ $^

clean:
	$(RM) flight .*.sw?
