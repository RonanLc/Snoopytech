#include "LettreMorse.hpp"

using namespace std;

class Traducteur{
    public :
        Traducteur(const char mot[30]);
        const char* get_sequence();
        void clignotements(const uint8_t pin);

        // ~Traducteur();

    private:
        char mot[30]; // le mot à traduire
        unsigned short int longueur_mot; // sa longueur
        char sequence_finale[180]=""; // contient la sequence de tous les clignotements du mot Ex:"---|--|-|"

        void ajouter_lettre_morse(const char lettre);
        void changer_etat_pin(const uint8_t pin);


        // varaibles de gestion des temps de clignotements
        const unsigned short int trait_long=3000;
        const unsigned short int trait_court=1000;
        const unsigned short int intervalle_court=500;
        const unsigned short int intervalle_long=1000;
        unsigned long int timer;

        unsigned short int indice_courant=0; // l'indice du caractère du mot que l'on traite
        char car_courant;

        bool initialisation=true;
        bool etat=true; // etat du pin HIGH/LOW


};
