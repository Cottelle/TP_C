tests: tests.o ca_malloc.o
	gcc -o tests tests.o ca_malloc.o

tests.o: tests.c
	gcc -o tests.o -c tests.c

ca_malloc.o: ca_malloc.c
	gcc -o ca_malloc.o -c ca_malloc.c

clean:
	rm *.o