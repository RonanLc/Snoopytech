# **Configuration du service**

Lorsque le script et le timer ont été dans le dossier `/etc/systemd/system`, on peut lancer ces services et les activer.

On recharge les services au préalable :

    sudo systemctl daemon-reload

On lance les deux services :

    sudo systemctl start <fichier.service>
    sudo systemctl strat <fichiertimer>

On les active : 

    sudo systemctl enable <fichier.service>
    sudo systemctl enable <fichier.timer>

Le service et le timer ont été lancé.
 