objects = main.o thread.o
cc = gcc
edit : $(objects)
	cc -o edit $(objects) -lpthread

main.o: main.c thread.h
	cc -c main.c
thread.o: thread.c thread.h
	cc -c thread.c
.PHONY : clean
clean:
	rm edit $(objects)