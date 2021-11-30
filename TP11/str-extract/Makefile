tests: tests.o str-extract.o
	gcc -o tests tests.o str-extract.o -g

str-extract.o: str-extract.c
	gcc -o str-extract.o -c str-extract.c -g 

tests.o: tests.c
	gcc -o tests.o -c tests.c -g

clean:
	rm *.o