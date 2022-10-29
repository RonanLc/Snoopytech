# Séance 1 - 14/10/2022
## Travail réalisé

Lors de cette première séance je me suis chargé de la modélisation du corps de notre robot sur Fusion360.
En suivant les plans que nous avions fixés avec Ronan, j'ai modélisé plusieurs pièces:
- la plaque de support à laquelle viendront se fixer les composants
- le cadre servant à maintenir les plaques de support et les tubes
- le tube autour duquel les pattes pivoteront
- des entretoises pour assurer la solidité du corps 
- des équerres pour éviter de perdre l'orthogonalité entre les plaques et les cadres


![Resume](https://user-images.githubusercontent.com/95374519/195982006-61ebdf0e-ffb6-454f-8b92-c16641e4df19.png)


Les pièces en rose sont en plexiglass (plastique pmma). Les pièces en vert sont en fibre de carbone. Les pièces en bleu sont en PLA. Les pièces en jaune sont en acier.

J'ai associé les pièces vertes au granite car sa masse volumique est proche de celle de la fibre de carbone (qui n'est pas disponible sur fusion). La masse volumique du granite (2,7g/cm3) étant superieure à celle de la fibre de carbone (1,95g/cm3), on peut surévaluer la masse totale du corps à 1,16kg.


J'ai également fait de recherches sur les entretoises existantes sur le marché. Il nous faut des entretoises d'une longueur de 86mm, ce qui ne semble pas disponible à la vente. Il nous sera peut-être plus judicieux de les imprimer nous même. 

## Objectifs pour la prochaine séance
-  Poursuivre et assister Ronan dans la modélisation de certaines pièces des pattes (épaule, transmission..)


# Worksession 2 -17/10/2022

## Camera and ultrasound sensor
During this session, my work was focused on the recherch and the conception/design of a piece allowing our camera and ultrasound sensor to rotate at an angle of 180°. 
Each sensor will have its own support, which will use a servo motor SG-90 to rotate. 
Thus, I needed to design a support for the servo that makes its rotation axis the same as the support's swivel axis.
This allows to reduce the amount of transmissions between the motor and the swivel axis.


![resume_2](https://user-images.githubusercontent.com/95374519/197337077-3adbb274-ee52-422d-9606-3235384c4bda.png)


All the designed parts will surely be 3D printed. 

## Force study

Furthermore, I got interested in the sturdiness and strength of the body of the robot.
So, I conducted a force study on the body thanks to Fusion360.
When applying a force described by a norm of 20N (the equivalent of a 2kg weight), vertical and directed towards the ground, on the frame of the body at the extremities of the tubes, no distorsions are to be seen. 


![simulation_force](https://user-images.githubusercontent.com/95374519/197337097-ff3649e2-45c0-491a-bdb3-3d2f77c80af3.png)


On the picture above, the colours close to blue reprensent an absence of distorions of the piece when put under stress. On the other side, the lighter colours represent a strong distorsion when the body undergoes stress.
Thereby, the body seems capable of withstanding the totale weight that it will be exposed to. 


# Worksession 3 - 28/10/2022

## Motor and support
Over this session, I focused of the implementation of the brushless motors we will be using (ACK-5312CP).
I began by modeling it from the dimensions found on the merchant's website.


[Photo]![brushless](https://user-images.githubusercontent.com/95374519/198837114-64c4d344-b746-41b4-a09e-99b204f7412f.png)


My next aim was to find a solution allowing us to link the motors to the body.
I started by sketching on paper ideas around a support to maintain the motor at a vertical position. This fisrt set of support will be used for
the motors that lead the shoulder of the leg.


![equerre_support_moteur](https://user-images.githubusercontent.com/95374519/198837136-a1d74fb8-9efb-4259-be37-b19174419a9a.png)


The first support holds the motor by its foot, while the other holds it by its axe.
I haven't figure out yet if the support that holds the motor by the foot will be 3D printed or not, the other possibility being that we could 
make it in steel. In the case we make it in steel, we might not need a support for the motor's axe. 
Thus, I only modeled the support for the motor's foot, since the modeling for the axe is similar.

## Assmebly
Finally, I attached the head desgined last week to the body to get a first preview of the assembly.

![assembly_head](https://user-images.githubusercontent.com/95374519/198837129-d87fb6bd-d6a1-41e4-b9e3-22690e76c07c.png)

