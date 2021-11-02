tests: tests.o linked-list.o
	gcc -o tests linked-list.o tests.o 

linked-list.o: linked-list.c 
	gcc -o linked-list.o -c linked-list.c 

tests.o: tests.c 
	gcc -o tests.o -c tests.c 

clean:
	rm *.o