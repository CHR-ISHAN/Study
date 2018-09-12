.PHONY:clean
	all:main mycat
main:main.o libmymath.so
	gcc $< -o $@ -L. -lmymath
mycat:mycat.o
	gcc $^ -o $@
libmymath.so:
	gcc -fPIC -shared -o $@ add.c
%.o:%.c
	gcc -c$< -o $@
clean:
	rm -rf *.o
