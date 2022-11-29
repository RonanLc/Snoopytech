#include "LettreMorse.hpp"

using namespace std;

/*
 * Constructeur de la classe LettreMorse
 * Prend en entrée une lettre et créer une sequence de signaux liée à celle-ci
*/
LettreMorse::LettreMorse(const char lettre_a_trad){
    this->lettre=lettre_a_trad; // on garde la lettre d'origine 
    traduction_lettre(lettre_a_trad);
}


/*
Renvoie la sequence de la lettre courante
*/
char* LettreMorse::get_sequence(){
    return this->sequence;
}


/*
Prend en entrée une lettre et associe une sequence de - et . que l'on stocke
dans l'atrribut sequence de l'objet
Conserve le nombre de clignotement
*/
void LettreMorse::traduction_lettre(char lettre){

    switch(lettre){
    case 'a':
        strcpy(this->sequence,".-");
        break;
    case 'b':
        strcpy(this->sequence,"-...");
        break;
    case 'c':
        strcpy(this->sequence,"-.-.");
        break;
    case 'd':
        strcpy(this->sequence,"-..");
        break;
    case 'e':
        strcpy(this->sequence,".");
        break;
    case 'f':
        strcpy(this->sequence,"..-.");
        break;
    case 'g':
        strcpy(this->sequence,"--.");
        break;
    case 'h':
        strcpy(this->sequence,"....");
        break;
    case 'i':
        strcpy(this->sequence,"..");
        break;
    case 'j':
        strcpy(this->sequence,".---");
        break;
    case 'k':
        strcpy(this->sequence,"-.-");
        break;
    case 'l':
        strcpy(this->sequence,".-..");
        break;
    case 'm':
        strcpy(this->sequence,"--");
        break;
    case 'n':
        strcpy(this->sequence,"-.");
        break;
    case 'o':
        strcpy(this->sequence,"---");
        break;
    case 'p':
        strcpy(this->sequence,".--.");
        break;
    case 'q':
        strcpy(this->sequence,"--.-");
        break;
    case 'r':
        strcpy(this->sequence,".-.");
        break;
    case 's':
        strcpy(this->sequence,"...");
        break;
    case 't':
        strcpy(this->sequence,"-");
        break;
    case 'u':
        strcpy(this->sequence,"..-");
        break;
    case 'v':
        strcpy(this->sequence,"...-");
        break;
    case 'w':
        strcpy(this->sequence,".--");
        break;
    case 'x':
        strcpy(this->sequence,"-..-");
        break;
    case 'y':
        strcpy(this->sequence,"-.--");
        break;
    case 'z':
        strcpy(this->sequence,"--..");
        break;
    default:
        strcpy(this->sequence,"");
        break;
    }
    
    this->nb_cligno=strlen(this->sequence) ; // on conserve le nombre de clignotment total

}
