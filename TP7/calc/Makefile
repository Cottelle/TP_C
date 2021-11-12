calc: calc.o calc-io.o parser.o
	gcc -o calc calc.o calc-io.o parser.o

calc-io.o: calc-io.c
	gcc -o calc-io.o -c calc-io.c

parser.o: parser.c
	gcc -o parser.o -c parser.c

clean:
	rm *.o