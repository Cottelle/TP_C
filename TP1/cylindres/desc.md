# Empilement de cylindres
inspiré de http://www.france-ioi.org

Il y a 3 zones. Sur la première zone se trouve 3 disques de rayons croissants. 

Vous controler un robot, et le but est de déplacer tous les disques de la zone 1 à la zone 3 en respectant ces deux règles :
* on ne peut déplacer qu'un disque à la fois, car ils sont très lourds ;
* on ne peut jamais poser un disque sur un disque plus petit que lui, car sinon l'empilement s'effondrerait !

## Commandes pour cet exercice

Le robot peut exécuter cette instruction :
```
Déplacer zoneSource -> zoneDestination
```

Lorsqu'il la reçoit, le robot prend le disque se situant au sommet de la zone désignée par zoneSource et le place au sommet de la zone désignée par zoneDestination (au sol si la zone est vide).
Pour identifier une zone, écrivez à la place de zoneSource et zoneDestination le numéro de la zone concernée.
En C, l'instruction s'écrit :
```c
deplacer(zoneSource, zoneDestination);
```

N'oubliez pas d'inclure la ligne suivante en haut de votre programme pour l'utiliser : `#include "hanoi.h"`

En guise d'exemple, voici un programme qui effectue quelques déplacements : de la zone 1, il déplace le premier disque dans la zone 3 et le deuxième dans la zone 2 ; puis il remet le premier dans la zone 1.
```c

#include "hanoi.h"
int main()
{
   deplacer(1, 3);
   deplacer(1, 2);
   deplacer(3, 1);
}
```
