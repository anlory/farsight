CFLAGS = -Wall -g -O0
CC = gcc

SRC = ${wildcard *.c}
OBJ = ${patsubst %.c, %, $(SRC)}

all:$(OBJ)

%:%.c
	$(CC) $(CFLAGS) -o $@ @<
.PHONY:clean all
clean:
	@ - $(RM) $(OBJ) .*.sw?
