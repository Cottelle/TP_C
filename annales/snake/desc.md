
# Snake
Commencez par renommer le fichier game_io.c.sujet en game_io.c


## TP Noté 4h
Le TP noté consiste à ajouter des fonctionnalités au jeu 'snake' (dont le code est disponible ici : https://git.unistra.fr/bramas/snake )

Tout d'abord, il faut coder la fonction qui permet de sauvegarder l'état du jeu (terminer la fonction `save_game` qui se trouve dans le fichier `game_io.c`).

Ensuite, on veut ajouter le nom du joueur à l'écran:

* Le nom doit donc faire parti de l'état du jeu
Il doit être enregistré dans le fichier de sauvegarde lors de la sauvegarde.
* Il doit être chargé lors du chargement.
* Un argument de ligne de commande doit permettre de choisir un nom lorsqu'on commence une nouvelle partie. Attention, si le nom choisi par l'utilisateur contient la chaine "snake", le mot "snake" doit être remplacer par ce texte : __/\_/\_/`oo
De même pour le texte "Snake". Par exemple si je choisi comme nom "happy snake", le texte qui devra s'afficher devra être : happy __/\_/\_/`oo
un nom par défaut doit être défini si aucun nom n'est donnée.
* Lorsque tout ce qui précède fonctionne, et a été testé avec des tests unitaires, le texte "Joueur : LE_NOM_DU_JOUEUR"  pourra être affiché à l'écran avec la fonction tps_drawText(posX, posY, text) (voir la documentation : https://bramas.gitlab.io/libtps.h/tps_gui.h.html#tps_drawText). Pour la position, une solution peut être d'agrandir légèrement la hauteur de la fenêtre (de 40 par exemple) et d'afficher le texte en bas de la fenêtre, la position y:=cell_size(game)*game->map_size + 5 et avec x une valeur quelconque qui vous semble jolie. (vous pouvez modifier ces valeurs comme vous le voulez). Dans ce cas, pour que ce soit jouable, il faudrait aussi dessiner le mur du bas avec tps_drawLine.
* A côté du nom du joueur, indiquer le score actuel (la longueur du serpent). On pourra utiliser la fonction sprintf afin de facilité la création de chaîne de caractères à partir d'autres chaines et de nombres.
* Ajouter un code de triche! Si la personne choisi comme nom "ILoveCProgramming" alors le serpent a le droit de se déplacer sur sa queue (normalement cela provoque la fin du jeu). On pourra penser à ajouter une condition de victoire qui arrête le jeu lorsque la longueur du serpent à atteint son maximum.
* Ajouter un autre code de triche! Si la personne choisi comme nom "CIsMyFavoriteProgrammingLanguage" alors le serpent a le droit de se déplacer sur sa queue et les murs n'existent plus. Lorsque le serpent sort de la map à droite, il réapparaît à gauche et inversement, lorsqu'il sort de la map en haut il réapparaît en bas et inversement.


Les deux derniers points ne compterons que très peu (voir uniquement en bonus) donc ils doivent être réalisés uniquement lorsque tout ce qui précède est proprement réalisé.
