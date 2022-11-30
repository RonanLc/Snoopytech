#include "Arduino.h"

using namespace std;

/*
*Classe décrivant une lettre morse
*/
class LettreMorse{
    public :
        LettreMorse(const char lettre);
        void traduction_lettre(const char lettre); // traduit la lettre en suite de 1 et de 0
        char* get_sequence(); 
        // ~LettreMorse();

    private: 
        char lettre; // contient la lettre 
        int nb_cligno; // Nombre de clgnotement total pour la lettre 
        char sequence[6]; // sequence des clignotements.  Ex: "-.."

}; 
