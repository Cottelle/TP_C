# Déchiffrement 2

Comme l'exercice 'uncrypt', vous interceptez les communications ennemis et souhaitez les déchiffrer.

Cependant ici l'algorithme appliqué est le Chiffre de Vigenère [C'est quoi?](https://fr.wikipedia.org/wiki/Chiffre_de_Vigen%C3%A8re).


Chaque jour, les ennemis change la clé, mais on sait qu'elle fait 8 caractères de long.

Chaque jour les ennemis commencent par envoyer cette phrase pour se dire bonjour :
```
bonjour les amis.
```

Les caractères spéciaux (et espaces) ne sont pas pris en compte lors par le chiffrement, ainsi le 8eme caractère
de la clé servira à chiffrer la lettre 'l' du texte ci-dessus.

Ecrire un algorithme qui lit dans le terminal le texte envoyé ce jour par vos ennemis, le déchiffre, et affiche le résultat.

### Exemple

Entrée :
```
ocdmcih jrg qpwg. qrgogxcbi braqlb à 10v
```
Sortie :
```
bonjour les amis. attaquons demain à 10h
```
