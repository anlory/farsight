CC=gcc
CFLAGAS=-Wall -g -O0
SRC=$(wildcard *.c)
OBJS=$(patsubst %.c,%,$(SRC))

all:main.c client.c cJSON.c 
	$(CC) $(CFLAGAS) -o $@ $^  -lsqlite3 -lm -lpthread

clean:
	$(RM) $(OBJS) all  .*.sw?
