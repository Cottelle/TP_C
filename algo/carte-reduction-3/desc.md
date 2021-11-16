#Carte de réduction
crédit: france-ioi.org

La description est similaire au problème carte-reduction, la numérotation des cartes de fidélité a changée.

Vous êtes employé dans un cinéma et votre patron décide de lancer une offre spéciale.
Toute personne possédant une carte de fidélité a le droit, pendant un mois,
de voir un film gratuit par jour. Bien entendu certaines personnes vont essayer de
tricher en venant plusieurs fois au cinéma dans la même journée et votre travail
consiste à détecter ces tricheurs.

Si vous trouvez un tricheur, vous devez laisser votre caisse à un collègue,
et emmener le tricheur chez votre patron qui lui confisquera sa carte de fidélité.

### Entrée

La première ligne contient l'entier N, le nombre de clients de la journée.
Il y a ensuite N lignes, chaque ligne contient le code d'une carte de fidélité.
Un code d'une carte de fidélité est une suite de 5 lettres majuscules.

### Sortie

Vous devez écrire un seul entier, le numéro de carte de fidélité du premier tricheur que vous avez trouvé.
S'il n'y avait pas de tricheur, écrivez la valeur -1.

### Limites de temps

Temps : 0.5 s

### Limites

0 <= N <= 100 000, le nombre de clients venant au cinéma en une seule journée.


### Exemples

#### Exemple 1
entrée :
```
4
TQPDC
TCEXC
PQSMC
TCEXC
```

sortie :
```
TCEXC
```

#### Exemple 2
entrée :
```
3
TQPDC
TCEXC
PQSMC
```
sortie :
```
-1
```
