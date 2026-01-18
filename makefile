.PHONY: clean


main: util/array_util.c util/file_util.c main.c
	gcc -Wall -g util/array_util.c util/file_util.c main.c -lncurses -o main -MMD
#	make -C

-include main.d

clean:
	rm -f main
	rm -f *.d

