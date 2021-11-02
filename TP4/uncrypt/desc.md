# Déchiffrement

Vous interceptez les communications ennemis et souhaitez les déchiffrer.
On sait que les l'algorithme de chiffrement est une simple permutation des lettres.
C'est à dire qu'il existe une fonction qui transforme une lettre
(parmis les 26 lettres minuscules) en une autre tels que deux lettres
différentes ne sont pas chiffrées par une même lettre (il y a une bijection de l'ensemble
des lettres vers l'ensemble des lettres). Les autres signes ne sont pas chiffrés.

**Chaque jour les ennemis change leur fonction de chiffrement**.

Pour se dire bonjour, ils commencent par envoyer cette phrase :

```
monsieur jack, vous dactylographiez bien mieux que votre ami wolf.
```

Ecrire un algorithme qui lit dans le terminal le texte envoyé ce jour par vos ennemis, le déchiffre, et affiche le résultat.

### Exemple

Entrée :
```
kpexabhc qjwu, nphx gjwzsopfcjmiabd rabe kabhl vhb npzcb jka tpoy. jzzjvhpex gbkjae à 10i
```
Sortie :
```
monsieur jack, vous dactylographiez bien mieux que votre ami wolf. attaquons demain à 10h
```
