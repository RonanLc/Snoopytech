#ifndef SRC_LETTRE_MORSE_H_
#define SRC_LETTRE_MORSE_H_

class LettreMorse { // Convertit les lettres en morse
    public:
        LettreMorse();
        void morseConverter(int letter); // Traduit la lettre en morse
        const char* morse; // Contient la traduction morse de la lettre entrée
    private:
};

#endif