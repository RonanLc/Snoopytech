# **Gestion de la taille du fichier log avec logrotate**


Notre base de donnée est mise à jour toutes les 10 minutes.
On veut pouvoir accéder aux logs datant au plus de 7 jours.

On suppose qu'une erreur retranscrite dans le log contient 2000 caractères (soit 2000 octets). 

Une erreur à chaque lancement du service rajoute 9000 (minutes) x 2000 (octets) par jour. 

Sur une période d'une semaine, un fichier contenant les erreurs générées par la sauvegarde de notre base de données (2000 octets toutes les 10 minutes, pendant une semaine) aurait une taille de : 

    2000 (octets) x 9000 (minutes dans un jour) x 7 (jours) = 126 Mo

Ainsi, on veut que notre log ait une taille au plus de 126 Mo. 

Nous avons donc les configurations nécéssaires pour écrire notre fichier de configuration de log :

    - Les logs dateront au plus de 7 jours
    - Ils doivent contenir au plus 126 Mo
    - Nous voulons 4 fichiers log au plus (ce qui represente 4 semaines de log)
    - Nous les compresserons 


Création d'un fichier de configuration de log :

    sudo vim /etc/logrotate.d/mysql-dump 

On précise dans le fichier les commandes qui assureront nos restrictions.(voir `mysql-dump.conf`)



