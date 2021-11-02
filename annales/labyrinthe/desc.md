
## Labyrinthe

Bob se réveil dans la pièce d'un donjon qui possède 4 portes (numéroté de 0 à 3).
Il souhaite sortir du donjon. Par chance, sur le sol de la pièce est inscrit le nombre de portes qui
le séparent de la sortie. Il comprend rapidement que chaque pièce du donjon est identique (uniquement ce nombre peut varier) et
que la pièce contenant le nombre `0` contient un escalier permettant de sortir du Donjon.

Chaque pièce est une instance d'un type structure `Piece` possédant comme attributs:
* un tableau `portes` de pointeurs vers `Piece`.
* un entier `distance`.

La structure est déjà définie dans le fichier `solveur.h` et il ne faut pas la modifier.

La fonction `main` permet de générer
   un donjon, dont la taille est lue dans le terminal, et d'afficher le résultat (après l'appel à la fonction `sortir`).

* **Vous devez écrire une fonction `sortir` dans le fichier `solveur.c`** (dont la déclaration est déjà présente dans le fichier `solveur.h`)
   qui prend en paramètre un pointeur vers `Porte` (la porte de départ)
   et affecte **à l'aide de pointeurs passés en arguments**, un tableau d'entiers et un entier (passés en arguments par pointeurs).
   Le tableau correspond aux numéros des portes qu'il faut empreinter pour sortir du donjon et l'entier correspond à la taille du tableau.
* **Enfin vous devez créer un Makefile** permettant de compiler le programme `main` à partir du fichier `main.c`.

La fonction `generer_donjon` permettant de générer le donjon est déclarée dans le fichier `generateur.h` et implémentée dans `generateur.c`)


Limit: taille du donjon <= 3000 x 3000

### Exemples
#### Exemple 1

Entrée:
```
2
```
Sortie:
```

```
Rien ne s'affiche car Bob se trouve déjà sur la pièce contenant l'escalier vers la sortie.

#### Exemple 2

Entrée:
```
3
```
Sortie:
```
porte 0
porte 0
porte 3
```

Ce chemin aurait aussi fonctionné:
```
porte 3
porte 0
porte 0
```
