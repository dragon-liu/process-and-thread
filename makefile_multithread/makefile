objects = main.o
cc = gcc
edit : $(objects)
	cc -o edit $(objects) -lpthread

main.o: main.c 
	cc -c main.c
.PHONY : clean
clean:
	rm edit $(objects)