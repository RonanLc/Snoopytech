# **Installation de mysql et importation de la base de données**

## **Installation de mysql**

L'installation de mysql sous Xubuntu commence avec la commande suivante :

    sudo apt install mysql-client-core-8.0 

Cette commande demande à l'utilisateur de saisir un mot de passe pour l'utilisateur `root`. Celui-ci peut dès à présent configurer les bases de données.

Par soucis de sécurité, on exécute la commande suivante :

    sudo mysql_secure_installation

Plusieurs options de sécurité sont proposées à l'utilisateur, qui doit saisir sa réponse dans le terminal.

On vérifie que le service `mysql` est en marche avec la commande suivante :

    sudo systemctl status mysql

Si on voit que le service est actif, l'installation est terminée.

## **Importation de la base de donnée**

Pour télécharger la base de donnée à l'adresse https://www.mysqltutorial.org/wp-content/uploads/2018/03/mysqlsampledatabase.zip, on saisie la commande suivante : 

    wget https://www.mysqltutorial.org/wp-content/uploads/2018/03/mysqlsampledatabase.zip

Cela télécharge le dossier compressé dans le répertoire courant. Il reste qu'à décompresser ce dernier : 

    unzip <dossier_téléchargé>

La commande produit un fichier `mysqlsampledatabase.sql` dans le répertoire courant. Il faut à présent le rajouter au serveur `mysql`.

Pour importer la base de donnée téléchargée dans le serveur `mysql`, il faut au prélable se connecter au serveur avec l'utilisateur `root`. Cela se décline de la façon suivante :

    sudo mysql -u root -p 

Cette commande demande de saisir le mot de passe crée précédemment.

A présent, nous sommes dans le terminal du serveur mysql, indiqué par la présence de `mysql>` qui précède la ligne de saisie.

Pour ajouter une base de donnée dans le serveur à partir d'un fichier `.sql`, on saisi la commande suivante :

    mysql> source <chemin_absolu_du_fichier.sql>;

On peut vérifier que l'on a bien ajouter la base de donnée en montrant toutes les bases de données : 

    mysql> show tables;

## **Authentification simple et nouvel utilisateur**

Dans cette partie on cherche à créer et à configurer un utilisateur qui pourra agir librement sur la seule base de donnée qui nous intéresse : `classicmodels`.

Pour se faire, il nous faut donc créer un utilisateur.
On commence par se connecter un tant que super-utilisateur afin de pouvoir apporter des changements au serveur mysql.

    sudo mysql -u root -p 

Une fois le mot de passe saisi, on se trouve dans le terminal du serveur mysql.

La création d'un nouvel utilisateur se fait avec la commande suivante :

    mysql> CREATE USER 'username'@'localhost' IDENTIFIED WITH authentification_plugin BY 'password';

où `username` est le nom du nouvel utilisateur à créer ; `localhost` la machine locale et `password` le mot de passe pour le nouvel utilisateur.

A ce stade, le nouvel utilisateur n'a pas encore les permissions pour agir de quelconque manière sur aucune des bases de données. 

On veut que cet utilisateur puisse accéder librement à la base de donnée `classicmodels`. On lui donne donc toutes les permissions (toujours en étant connecté dans le terminal msyql avec le super-utilisateur) :

    mysql> GRANT ALL ON classicmodels.* to 'username'@'localhost';

Ainsi, on est amené à croire que le nouvel utilisateur possède la plupart des droits sur la base `classicmodels` et toutes ses tables. 
Cependant, afin de pouvoir sauvegarder cette base de donnée (cf. le script `dump-database.sh`), il faut à cet utilisateur une permission particulière :

    mysql> GRANT PROCESS ON *.* TO 'username'@'localhost';

De plus, on met en place un moyen de connection sans avoir besoin de saisir un mot de passe. Cela permet d'éviter les erreurs lors du lancement du service (cf dump-database.service).

    mysql> ALTER USER 'username'@'localhost' IDENTIFIED WITH auth_socket;

Finalement, notre nouvel utilisateur peut agir librement sur la base de donnée `classicmodels` et peut se connecter au serveur `mysql` sans avoir besoin de saisir un mot de passe. 
