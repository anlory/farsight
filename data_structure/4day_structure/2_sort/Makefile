CC = gcc
CFALGS = -Wall -g -O0

SRC = ${wildcard *.c}
OBJS = ${patsubst %.c,%,$(SRC)}

all:$(OBJS)

%:%.c
	    $(CC) $(CFALGS) -o $@ $^

clean:
	    $(RM) $(OBJS) .*.sw?
