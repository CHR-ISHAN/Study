.PHONY:clean
mystat : stat.o
	gcc -o bin/mystat obj/stat.o
stat.o: src/stat.c
	gcc -c src/stat.c -o obj/stat.o
clean:
	rm -rf obj/* bin/*
