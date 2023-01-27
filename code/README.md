# Bilan programmation du 27/01/2023

## Introduction

Ce répertoire rassemble tous les programmes et parcelles de code qui ont été crées/utilisés dans le cadre de ce projet.
Il s'agit, pour la plupart, de code C++ car nous sommes encore au stade d'expérimentation. 
Nous implementerons des fonctions de traitements d'images et de classifications d'images à bord de la Jetson Nano lorsque nous aurons achevé d'écrire les librairies destinées à rendre notre robot fonctionnel.

## Librairies et classes utilisées/importées

Voici une liste de librairie que nous utilisons afin de rendre certains capteurs/actionneurs opérationnels :

1. [I2Cdev](https://github.com/jrowberg/i2cdevlib) 

Cette librairie facilite le contrôle de module communiquant avec l'Arduino par le biais de bus I2C. Nous l'utilisons notamment dans la librairie ```MPU6050```.

2. [MPU6050](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050)

Cette librairie est destinée à controler le capteur GY-521 (gyroscope). Elle permet d'utiliser le DMP (digital motion processor) qui est sollicité pour renvoyer des données stables et lisibles. 
Nous implementons cette librairie dans la classe ```Gyroscope```.

3. [ServoTimer2-master](https://github.com/nabontra/ServoTimer2)

Cette librairie permet de controler les servomoteurs et ESC de notre robot en évitant de créer des conflits liés au Timer1 de l'Arduino. Nous l'implementons dans la classe ```CameraMount```.

## Librairies et classes apportées

Cette section regroupe les classes et les programmes que nous avons écrits. 

1. [Gyroscope](https://github.com/RonanLc/Snoopytech/tree/main/code/lib/Gyroscope)

Cette classe facilite l'utilisation du gyroscope GY-521. Elle implémente les classes MPU6050 et I2Cdev. 

Utilisation: 
- permet d'initialiser un gyroscope sur le pin 2 d'une Arduino Uno
- calcule et renvoie l'accelération réelle et le roulis/tangage/lacet du capteur

2. [CameraMount](https://github.com/RonanLc/Snoopytech/tree/main/code/lib/CameraMount) 

Cette classe crée des objets contrôlant une nacelle de notre robot. Une nacelle est une structure sur laquelle se monte des capteurs qui ont besoin d'une orientation indépendante du corps du robot. La nacelle se compose de deux servomoteurs SG-90.

Utilisation:
- permet d'initialiser les deux servomoteurs sur les pins passés en paramètre
- change le roulis et/ou le tangage de la nacelle selon un angle passé en paramètre
- réinitialise la position de la nacelle 
- renvoie la postion de la nacelle

## Programme d'essai

1. [rpm_brushless](https://github.com/RonanLc/Snoopytech/tree/main/code/test/rpm_brushless.ino)

Ce programme permet de récuperer la vitesse de rotation d'un moteur brushless grâce à un capteur à effet Hall. Nous l'utilisons dans l'étude de l'asservissement de position des moteurs. 

2. [main.cpp](https://github.com/RonanLc/Snoopytech/blob/main/code/src/main.cpp) 

Ce programme est celui qui sera exécuté sur l'Arduino. Il regroupe toutes les classes utilisées. 
Pour l'instant, il permet de changer l'orientation des deux nacelles du robot selon l'inclinaison du gyroscope. 
