#include "Arduino.h"

using namespace std;

/*
*Classe décrivant une lettre morse
*/
class LettreMorse{
    public :
        LettreMorse(const char lettre);
        void traduction_lettre(const char lettre); // traduit la lettre en suite de "-" et "."
        char* get_sequence(); 
        // ~LettreMorse();

    private: 
        char lettre; // contient la lettre 
        int nb_cligno; // Nombre de clignotement total pour la lettre 
        char sequence[5]; // sequence des clignotements.  Ex: "-.."

}; 
