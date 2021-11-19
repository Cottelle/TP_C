# BMP-message

Dézippez l'archive Archive.zip et ensuite :

* Corrigez l'erreur valgrind qui survient lorsque l'on encode un message (test `Execution encode` dans le fichier `test.sh`).
* Complétez la fonction decode afin de récurérer (et afficher) le message caché dans une image.
* modifiez la fonction encode afin de vérifier s'il y a assez de pixel dans l'image pour écrire le message (envoyer une erreur sinon, le type d'erreur doit être ajouté dans l'enum correspondant).
* Implémentez le fait que si l'utilisateur ne donne pas de message avec l'option `-m` lors de l'encodage, alors on considère que le message est lu depuis l'entrée standard. Il faut donc lire entièrement l'entrée standard et le mettre dans le champs `messageToEncode`
