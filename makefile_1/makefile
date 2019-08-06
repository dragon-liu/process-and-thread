objects = main.o CwhitLf.o 
cc = gcc
edit : $(objects)
	cc -o edit $(objects)

main.o: main.c main.h 
	cc -c main.c
CwhitLf.o: CwhitLf.c CwhitLf.h
	cc -c CwhitLf.c
.PHONY : clean
clean:
	rm edit $(objects)