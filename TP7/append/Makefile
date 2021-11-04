tests: tests.o append.o
	gcc -o tests tests.o append.o

tests.o: tests.c
	gcc -o tests.o -c tests.c

append.o: append.c
	gcc -o append.o -c append.c
clear:
	rm *.o