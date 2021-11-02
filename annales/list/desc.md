## List

Le fichier `list.c` contient plusieurs fonctions (déclarées dans `list.h`) permettant de créer et de manipuler
des structures de type `List`.
Le problème est que la fonction `list_size` doit parcourir toute la liste afin d'en connaitre la taille, cela peut être
amélioré pour être plus rapide.


Une méthode consiste à conserver l'information de la taille de la liste dans un attribut de la structure `List`.
Lors de la création de la liste, la taille est 0, puis la taille doit être mise à jour lors de l'ajout ou la suppression d'éléments.

Vous devez :
* **Ajouter un attribut `size` de type `size_t` à la structure `List`** afin de conserver à tout moment la taille de la liste.
* **Mettre à jour dans `list.c`** les fonctions afin d'utiliser ce nouvel attribut.
* **Créer un `Makefile`** pour pouvoir générer l'éxecutable `main` qui correspond au programme se trouvant dans `main.c`.
* En utilisant `valgring ./main`, vous observerez que le programme contient une fuite mémoire. **Corrigez cette fuite mémoire.**

### Méthode de test

La rapidité de la fonction `list_size` sera testée avec le programme présent dans `main.c`. Le programme lit et ajoute tous les entiers
entrés dans le terminal jusqu'à ce que 0 soit entré. Pour tester le programme avec beaucoup de nombres, on peut renseigner un fichier comme entrée
du terminal ainsi:
```
$ ./main < fichier
```
cela revient à exécuter le programme `./main` et à entrer dans le terminal le contenu du fichier.
3 fichiers de tailles variables sont fournis pour tester votre programme (`small.in`, `large.in` et `huge.in`)
que vous pouvez utiliser ainsi :
```
$ ./main < small.in
```
