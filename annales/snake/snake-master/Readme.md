
## Compilation

Penser à mettre à jour la librairie tps avec `sudo update-libtps`

ensuite : `make && bin/snake`

## tests

```
cd tests
make cov
```

-l FICHIER    permet de charger la partie contenu dans FICHIER
-s TAILLE     taille de la carte
-f DUREE      durée d'une frame (en milliseconde)
-c            utiliser la couleur (non implémentée)
-h            afficher l'aide
