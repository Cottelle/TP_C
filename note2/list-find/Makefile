tests: tests.o list.o
	gcc -o tests tests.o list.o

tests.o: tests.c 
	gcc -o tests.o -c tests.c

list.o: list.c
	gcc -o list.o -c list.c

clean:
	rm *.o