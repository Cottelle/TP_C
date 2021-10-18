CFLAGS?=-Werror -Wextra -Wall -g

tests: matrix-In.o tests.o
	gcc $(CFLAGS) -o tests $^

matrix-In.o: matrix-In.c matrix-In.h
	gcc $(CFLAGS) -o matrix-In.o -c matrix-In.c

tests.o: tests.c
	gcc $(CFLAGS) -o tests.o -c tests.c

clean:
	rm -f *.o
	rm -f tests
