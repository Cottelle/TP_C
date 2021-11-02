tests: tests.o test-tab.o
	gcc -o tests tests.o test-tab.o -lm

tests.o: tests.c
	gcc -o tests.o -c tests.c -lm

test-tab.o: test-tab.c
	gcc -o test-tab.o -c test-tab.c -lm


	
clean :
	rm -rf *.o

