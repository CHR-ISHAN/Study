.PHONY : main clean
main : pb.o
		gcc $^ -o $@
%.o : %.c
		gcc -c $< -o $@
clean :
		rm -rf *.o
