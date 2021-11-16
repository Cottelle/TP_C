tests: tests.o checked-int.o
	gcc -o tests tests.o checked-int.o

tests.o: tests.c
	gcc -o tests.o -c tests.c

checked-int.o: checked-int.c
	gcc -o checked-int.o -c checked-int.c

clean:
	rm *.o