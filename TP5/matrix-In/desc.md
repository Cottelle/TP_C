## Matrice identité

Ecrire **dans un fichier "matrix-In.c"** trois fonctions `matrixI1`, `matrixI2` et `freeMatrix` dont les prototypes sont donné dans le fichier "matrix-In.h"

Les fonctions `matrixI1` et `matrixI2` doivent permettrent de générer une matrice identité de taille `nxn` (`n` lignes et `n` colonnes). Elle alloue de la mémoire, et c'est celui qui appelle ces fonctions qui est responsable de libérer cette mémoire.

Les deux fonctions `matrixI1` et `matrixI2` effectuent la même chose, mais retournent le résultat différemment.
En cas de problème, ces fonctions doivent retourner le pointeur `NULL`, et ne doivent pas avoir allouée de mémoire non libérée.

La fonction `freeMatrix` permet de libérer la mémoire allouée pour une matrice gérérée par l'une des deux autres fonctions.


Compiler avec make!
