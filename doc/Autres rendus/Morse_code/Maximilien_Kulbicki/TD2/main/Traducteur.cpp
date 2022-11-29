#include "Traducteur.hpp"

using namespace std;

/*
Constructeur de la classe traducteur
Prend un mot et un pin en entrée, et traduit chaque lettre en sequence de clignotements
Les clignotements sont ajoutés dans sequence_finale
*/
Traducteur::Traducteur(const char new_word[90], const uint8_t new_pin){
    strcpy(this->mot,new_word); // on garde en mémoire le mot à traduire

    for(size_t i=0;i<strlen(new_word);i++){
        this->ajouter_lettre_morse(new_word[i]);
    }

    this->longueur_mot=strlen(this->sequence_finale);// et sa longueur

    this->pin=new_pin; // on garde en mémoire le pin
    // Serial.println(this->pin);
};

/*
Ajoute la traduction en morse d'une lettre à la séquence finale de clignotements.
Si le caractère en paramètre est une lettre, ajoute sa traduction.
S'il s'agit d'un espace, rajoute un espace à la séquence finale.
Sinon, n'ajoute rien.
*/
void Traducteur::ajouter_lettre_morse(const char lettre){
    
    if ( (lettre>=97 && lettre<=122) || (lettre>=65 && lettre<=90)){ // cas où le caractère est une lettre minuscule ou majuscule
        LettreMorse lettre_morse(lettre);
        strcat(this->sequence_finale,lettre_morse.get_sequence());
        strcat(this->sequence_finale,"|"); // ajout d'un espace entre les lettres 
    }

    else if (lettre==32){ // cas où le caractère est un espace
        strcat(this->sequence_finale,"|"); // on ajoute deux espaces pour differencier deux mots
    }
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
    Serial.print(car_courant);
};

/*
Méthode de gestion des clignotements de la sequence_finale
*/
void Traducteur::clignotements(){

    if(this->initialisation){ // initialise le timer
        this->initialisation=false;
        this->car_courant=this->sequence_finale[this->indice_courant]; // pose comme caractere courant le premier caractere du mot
        changer_etat_pin(this->pin);
    }

    if (this->indice_courant < this->longueur_mot){ // tant qu'on a pas traité toutes les lettres
        switch (this->car_courant)
        {
        case '-': // cas où la led est allumée et en clignotement long
            if (millis()-this->timer >= this->trait_long){ // si la led est restée allumé assez longtemps
                this->indice_courant++;
                this->car_courant=' '; // le caractere courant devient un ' ', signe qu'on est en phase de transition de caractere
                changer_etat_pin(this->pin);
            }
            break;

        case '.': // cas où la led est allumée et en clignotement court
            if (millis()-this->timer >= this->trait_court){
                this->indice_courant++;
                this->car_courant=' ';
                changer_etat_pin(this->pin);
            }
            break;

        case '|': // led éteinte et transition entre lettre/mot
            if (millis()-this->timer >= this->intervalle_long){
                this->indice_courant++;
                this->car_courant=' ';
                changer_etat_pin(this->pin);
            }
            break;

        case ' ': // led éteinte et transition entre symbole
            if(millis()-this->timer>=this->intervalle_court){
                this->car_courant=this->sequence_finale[this->indice_courant];
                changer_etat_pin(this->pin);
            }
            break;

        default:
            Serial.println("Probleme de caractere");
            break;
        }

    }

    else{
        digitalWrite(this->pin,LOW); // on éteint la led
    }

}
