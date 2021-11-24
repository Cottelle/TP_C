# Le bug des moteurs de recherche
(crédit: france-ioi.org)

Dans une galaxie très, très lointaine, on raconte que les moteurs de recherche on un bug, et que si
une personne cherche sur un moteur de recherche le nom de ce moteur de recherche, l'univers implose.
C'est-à-dire qu'il ne faut surtout pas que quelqu'un cherche le terme "Googol" sur le moteur de recherche Googol.

Pour éviter que cela ne se produise, les personnes vivant dans cette galaxie on eu une idée: toutes les requêtes de tous les moteurs
de recherche arrivent dans un système central qui redirige chaque requête vers un moteur de recherche de telle sorte
que le terme recherché ne soit pas le nom du moteur de recherche et ainsi éviter que l'univers n'implose.
Le système central choisi un moteur de recherche et tous les requêtes qui arrivent sont envoyé uniquement vers ce moteur de recherche.
Le système peut à tout moment décider de motifier le moteur de recherche cible qui reçoit toute les requêtes.
Les requêtes doivent être traitées dans l'ordre dans lequel elles arrivent et il faut à tout prix éviter
qu'une requête contenant le nom d'un moteur de recherche soit envoyée à ce moteur de recherche.

Votre tache est de calculer combien de fois au minimum, le système central doit changer de moteur de recherche cible,
en supposant que l'algorithme exécuté sur le serveur est optimal.

En entrée votre algorithme reçoit un nombre `n` qui correspond au nombre de moteurs de recherche
suivi de `n` lignes, une ligne pour chaque moteur de recherche.
Ensuite, votre algorithme reçoit un nombre `r` qui correspond au nombre de requêtes, suivi de `r` lignes,
une ligne pour chaque requête.
Votre programme (écrit dans un fichier `recherche.c`) doit afficher un unique entier qui correspond au nombre minimum de fois que le système centrale
doit changer de moteur de recherche cible.


### Exemples
#### Exemple 1
entrée :
```
5
Yeehaw
NSM
Dont Ask
B9
Googol
10
Yeehaw
Yeehaw
Googol
B9
Googol
NSM
B9
NSM
Dont Ask
Googol
```
sortie :
```
1
```
#### Exemple 2
entrée :
```
5
Yeehaw
NSM
Dont Ask
B9
Googol
7
Googol
Dont Ask
NSM
NSM
Yeehaw
Yeehaw
Googol
```
sortie :
```
0
```
