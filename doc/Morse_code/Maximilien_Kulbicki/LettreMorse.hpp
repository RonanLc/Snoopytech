#include "Arduino.h"

using namespace std;

class LettreMorse{
    public :
        LettreMorse(const char lettre);
        void traduction_lettre(const char lettre); // traduit la lettre en suite de 1 et de 0
        char* get_sequence(); 
        // ~LettreMorse();

    private: 
        char lettre; // contient la lettre 
        int nb_cligno; // Nombre de clgnotement total pour la lettre 
        char sequence[5]; // sequence des clignotements.  Ex: "-.."

}; 
