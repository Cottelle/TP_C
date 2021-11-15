main: main.o generateur.o solveur.o
	gcc -o main main.o generateur.o solveur.o 

main.o: main.c
	gcc -g -o main.o -c main.c

genereateur.o: genereteur.c
	gcc -g -o generateur.o -c generateur.c

solveur.o: solveur.c
	gcc -g -o solveur.o -c solveur.c

clean:
	rm *.o
