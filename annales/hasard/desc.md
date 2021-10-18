## Génération de nombres aléatoires

La fonction `rand` de la librairie standard ne permet pas de générer de nombres aléatoires très grands.
On souhaite générer des nombres contenant 10 chiffres (entre 0 et 9'999'999'999).
Alice et Bob ne sont pas d'accord sur la méthode à employer pour faire cela.
Alice pense qu'on peut utiliser la fonction `rand` pour générer 10 chiffres (entre 0 et 9) qui mis bout à bout
formeront un nombre aléatoire. Par exemple si les dix appels successifs donnent `0`, `8`, `1`, `2`, `5`, `0`, `1`, `3`, `3`, `9` alors le nombre
généré sera `812501339` (il peut arriver que le nombre fasse moins de dix chiffres).

Bob pense que la méthode d'Alice est trop coûteuse car elle appelle trop de fois la fonction `rand`. Bob propose donc
de n'appeler `rand` que deux fois, pour générer deux nombres entre 0 et 100'000 et de les multiplier entre eux pour
obtenir le nombre souhaité.

Alice n'est pas d'accord car avec cette méthode le nombre 10'000'000'000 pourra être obtenu alors que l'on souhaite un nombre à 10 chiffres
maximum. De plus certains nombres ne peuvent pas être obtenus, comme certains grands nombres premiers.

Après une longue discussion, Bob est d'accord avec Alice, mais il persiste et affirme que ces cas sont trop rares pour arriver
et donc il serait impossible de distinguer des nombres générés à l'aide de sa méthode, des nombres générés avec la méthode
d'Alice.

**Vous n'êtes pas de son avis et voulez aider Alice à prouver que Bob à tort!!**

Pour cela il faut effectuer un test à l'aveugle : on vous donne un tableau de `n` entiers à 10 chiffres maximum, et vous devez dire si
ces nombres ont été générés avec la méthode d'Alice ou la méthode de Bob.

Pour vous aider, Alice a préparé un programme (`tests.c`) et vous devez implémenter la fonction `test` dans un fichier `test-tab.c` (déclarée dans `test-tab.h`)
qui prend en arguments un tableau d'entiers `T` et un entier `n` (la taille du tableau `T`) et qui retourne `ALICE` si le tableau contient des
nombres générés avec la méthode d'Alice, ou `BOB` si vous pensez que c'est la méthode de Bob qui a généré les nombres du tableau.

**Vous ne devez pas toucher le fichier `test-tab.h` ni le fichier `tests.c`**. Vous pouvez compiler le programme tests et l'utiliser pour
tester votre fonction, ou créer d'autres fichiers. Le programme `tests.c` lit d'abord un entier correspondant au nombre de tests réalisés,
puis génère un tableau `T` aléatoirement selon la méthode d'Alice ou de Bob. Le tableau est ensuite envoyé à votre fonction `test` pour voir si elle détecte correctement qui a généré le tableau.

**Comme le programme est séparé en plusieurs fichiers, vous êtes responsable de la création du Makefile,**
**celui-ci doit contenir une règle pour générer l'exécutable `tests` et une règle clean**

### Particularité de l'évaluation

Le test étant probabiliste, il est possible que les deux méthodes fournissent des résultats similaires et donc impossible
d'être sûr à 100% de la méthode utilisée.

Ainsi, 100 tests seront réalisés, chaque test consiste à lire 100 entiers générés par Alice ou Bob et à appeler votre fonction test pour vérifier
si vous avez effectivement détecté quelle méthode à été utilisée.

Si votre fonction donne un résultat correct sur 97% des tableaux testés, alors vous recevez tous les points de l'exercice,
sinon, si votre méthode est correcte sur 70% des cas, alors vous recevez 20/100. Sinon vous ne recevez rien.

C'est pourquoi, le fichier `tests.c` contient déjà tout ce qu'il faut pour effectuer les 100 tests.
