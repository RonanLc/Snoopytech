# **Gestion de la taille du fichier /var/log/dump-mysql.log**

Pour gérer la taille de ce fichier, on récupère sa taille dans le script `dump-database.sh`.

Ensuite, selon la taille du fichier, on écrit dans le fichier sans supprimer le contenu présent ou au contraire on réecrit par dessus le fichier.

L'espace aloué pour le fichier est par défaut de 4 KO. On se base sur cette valeur pour savoir si l'on réecrit par dessus le fichier ou non. 

Si la taille du fichier dépasse 4Ko, on réecrit par dessus. 
Sinon, oon ajoute simplement les logs à la fin du fichier.