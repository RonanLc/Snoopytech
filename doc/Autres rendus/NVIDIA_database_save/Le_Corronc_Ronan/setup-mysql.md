Pour ce projet j'ai utilisé MySQL 8.0 sur Ubuntu, je vais expliquer comment l'installer puis l'utiliser.

<br />

# I - Mettre à jour ses package

Avant de commencer, il est recommandé de mettre à jour ses packages locaux avec les dernieres version disponible.

Pour ce faire vous pouvez utiliser les deux fonctions suivantes :

```shell
/$ sudo apt update
```
```shell
/$ sudo apt upgrade
```
<br />

# II - Installation de MySQL

Une fois les packages à jour, nous pouvons commencer à installer MySQL à l'aide de cette commande :

```shell
/$ sudo apt-get install mysql-server
```

L'installation peut prendre un certain en fonction de votre connexion internet.

MySQL est maintenant installé sur votre ordinateur.

# III - Sécuriser l'accès à MySQL

MySQL étant un puissant outils pour les bases de données, certaines peuvent être confidenciel. Pour cela, vous devez sécuriter l'accès à votre base de données.

Ainsi cette commande permet d'ajuster la sécurité du serveur MySQL

```shell
/$ sudo mysql_secure_installation
```

Un mot de passe vous sera demandé, il correspond au mot de passe d'accès à votre utilisateur MySQL et non à votre utilisateur Ubuntu.

![MySQL Secure Installation](assets/mysql_secure_installation.png)

De nombreuses questions vous seront demandé, je recommande de tout activer en indiquant Y (yes) à toutes.

Votre accès à MySQL est désormais sécurisé.

[lien](https://www.mysqltutorial.org/wp-content/uploads/2018/03/mysqlsampledatabase.zip)