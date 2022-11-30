#ifndef SRC_LETTRE_MORSE_H_
#define SRC_LETTRE_MORSE_H_

/**
 * Cette classe regroupe tous les éléments pour convertir des caractères en morse
 * 
 * Elle regroupe 1 fonction utilisable
*/
class LettreMorse {    
    public:
        LettreMorse();
        void morseConverter(int letter);
        const char* morse;                  // Contient la traduction morse de la lettre entrée dans morseConverter()
    private:
};

#endif