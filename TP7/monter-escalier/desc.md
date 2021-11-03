# Monter un escalier

Lorsqu'on monte un escalier on peut monter les marches une par une, deux par deux, ou bien en mélangeant les deux méthodes. Parfois on saute une marche, parfois deux (mais jamais trois ou plus, c'est beaucoup trop dangereux!!).

Le but de l'exercice est de compter le nombre de manières différentes de monter un escalier de `n` marches.

Par exemple, il y a 3 manières de monter un escalier de 3 marches :
* 1 marche, 1 marche, 1 marche
* 1 marche, 2 marches
* 2 marches, 1 marches

Votre programme doit s'appeler `monter-escalier` et doit accepter un unique argument de ligne de commande correspondant a un entier strictement positif `n` (autrement il doit afficher une erreur et quitter avec le code d'erreur 1).
Il doit ensuite afficher uniquement 1 entier, qui correspond au nombre de manière possible de monter un escalier contenant `n` marches.

### Exemples

```bash
$ ./monter-escalier 3
3
```

```bash
$ ./monter-escalier -1
Mauvais argument. Vous devez entrer un nombre entier strictement positif
```
