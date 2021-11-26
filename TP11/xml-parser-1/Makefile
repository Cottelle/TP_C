tests: tests.o xmlp.o
	gcc -o tests tests.o xmlp.o -g

tests.o: tests.c
	gcc -o tests.o -c tests.c -g 

xmlp.o: xmlp.c
	gcc -o xmlp.o -c xmlp.c -g

clean:
	rm -rf *.o