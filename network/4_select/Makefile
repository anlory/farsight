
cc = gcc

OBJS = tcp_srv_select tcp_cli

all:$(OBJS)

%:%.c link.c
	$(CC) -o $@ $^ 

clean:
	$(RM) .*.sw? $(OBJS)
