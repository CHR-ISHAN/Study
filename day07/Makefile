.PHONY : clean

CC=cc
CFLASS=-Wall -g
OBJS=main.o dlink.o
 all : main
main : $(OBJS)
		$(CC) $(CFLASS) $^ -o $@
%.o : %.c
		$(CC) $(CFLASS) -c $< -o $@
clean:
	rm - rf *.o
