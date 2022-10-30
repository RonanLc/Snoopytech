#include "Traducteur.hpp"

using namespace std;

/*
Constructeur de la classe traducteur
Prend un mot en entrée et traduit chaque lettre en sequence de clignotements
Les clignotements sont ajoutés dans sequence_finale
*/
Traducteur::Traducteur(const char new_word[30]){
    strcpy(this->mot,new_word); // on garde en mémoire le mot à traduire

    for(size_t i=0;i<strlen(new_word);i++){
        this->ajouter_lettre_morse(new_word[i]);
    }

    this->longueur_mot=strlen(this->sequence_finale);// et sa longueur
};

/*
Ajoute la traduction en morse d'une lettre à la séquence finale de clignotements
*/
void Traducteur::ajouter_lettre_morse(const char lettre){
    LettreMorse lettre_morse = LettreMorse(lettre);
    strcat(this->sequence_finale,lettre_morse.get_sequence());
    strcat(this->sequence_finale,"|"); // ajout d'un espace entre les lettres 
};

/*
Renvoie la sequence finale du mot courant
*/
const char* Traducteur::get_sequence(){
    return this->sequence_finale;
};

/*
Change l'état du pin 
*/
void Traducteur::changer_etat_pin(const uint8_t pin){
    switch (this->car_courant)
    {
    case '-':
        this->etat=true;
        break;
    case '.':
        this->etat=true;
        break;
    case '|':
        this->etat=false;
        break;
    case ' ':
        this->etat=false;
        break;
    default:
        Serial.println("Probleme etat");
        break;
    }

    this->timer=millis(); // on change le timer
    digitalWrite(pin,this->etat);
    Serial.println(car_courant);
};

/*
Méthode de gestion des clignotements de la sequence_finale
*/
void Traducteur::clignotements(const uint8_t pin){
    if(this->initialisation){ // initialise le timer
        this->initialisation=false;
        this->car_courant=this->sequence_finale[this->indice_courant]; // pose comme caractere courant le premier caractere du mot
        changer_etat_pin(pin);
    }

    if (this->indice_courant < this->longueur_mot){ // tant qu'on a pas traiter toutes les lettres
        switch (this->car_courant)
        {
        case '-': // cas où la led est allumée et en clignotement long
            if (millis()-this->timer >= this->trait_long){ // si la led est restée allumé assez longtemps
                this->indice_courant++;
                this->car_courant=' '; // le caractere courant devient un ' ', signe qu'on est en periode de transition de caractere
                changer_etat_pin(pin);
            }
            break;

        case '.':
            if (millis()-this->timer >= this->trait_court){
                this->indice_courant++;
                this->car_courant=' ';
                changer_etat_pin(pin);
            }
            break;

        case '|':
            if (millis()-this->timer >= this->intervalle_long){
                this->indice_courant++;
                this->car_courant=' ';
                changer_etat_pin(pin);
            }
            break;

        case ' ':
            if(millis()-this->timer>=this->intervalle_court){
                this->car_courant=this->sequence_finale[this->indice_courant];
                changer_etat_pin(pin);
            }
            break;

        default:
            Serial.println("Probleme de caractere");
            break;
        }

    }

    else{
        digitalWrite(pin,LOW); // on éteint la led
    }

}