latex-indent: latex-indent.o fonction.o
	gcc -o latex-indent latex-indent.o fonction.o

latex-indent.o:latex-indent.c
	gcc -o latex-indent.o -c latex-indent.c

fonction.o: fonction.c
	gcc -o fonction.o -c fonction.c

clean:
	rm *.o