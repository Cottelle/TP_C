reduc: reduc.o arbrebinaire.o
	gcc -o reduc reduc.o arbrebinaire.o

arbrebinaire.o: arbrebinaire.c
	gcc -o arbrebinaire.o -c arbrebinaire.c

reduc.o: reduc.c
	gcc -o reduc.o -c reduc.c

clean:
	rm *.o