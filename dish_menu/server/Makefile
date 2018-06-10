CC=gcc
CFLAGAS=-Wall -g -O0
SRC=$(wildcard *.c)
OBJS=$(patsubst %.c,%,$(SRC))

all:main.c cJSON.c server.c
	$(CC) $(CFLAGAS) -o $@ $^  -lsqlite3 -lm -pthread

clean:
	$(RM) $(OBJS) .*.sw?
