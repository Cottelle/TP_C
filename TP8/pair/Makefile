tests: tests.o pair.o
	gcc -o tests tests.o pair.o

tests.o: tests.c
	gcc -o tests.o -c tests.c

pair.o:pair.c
	gcc -o pair.o -c pair.c

clear:
	rm *.o