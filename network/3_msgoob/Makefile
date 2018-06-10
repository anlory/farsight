
CC = gcc
CFLAGS = -Wall -g -O0

OBJS = srv_tcp cli_tcp
all:$(OBJS)

%:%.c
	    $(CC) $(CFLAGS) -o $@ $^

clean:
	    $(RM) $(OBJS) 
