objects = main.o
cc = gcc
edit : $(objects)
	cc -o sumprocess $(objects) 

main.o: main.c main.h
	cc -c main.c 
.PHONY : clean
clean:
	rm sumprocess $(objects)