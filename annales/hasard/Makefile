all: tests

tests : test-tab1.o test-tab2.o tests.o
	gcc -o tests tests.o test-tab1.o test-tab2.o

test-tab2.o : test-tab.c
	gcc -o test-tab2.o -c test-tab.c  

test-tab1.o : test-tab.h
	gcc -o test-tab1.o -c test-tab.h

tests.o : tests.c
	gcc -o tests.o -c tests.c 
	
clean :
	rm -rf *.o

