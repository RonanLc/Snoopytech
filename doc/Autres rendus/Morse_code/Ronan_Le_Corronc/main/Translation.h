#ifndef SRC_TRANSLATION_H_
#define SRC_TRANSLATION_H_

class Translation {  // Convertit le morse en trame temporelle
    public:
        Translation();
        void binaryMorse(const char* morse); // Permet de convertir le morse en trame temporelle de 0 et 1 (correspondant à l'état de la LED au fil du temps)
        bool binary_tram[20] = {0}; // trame temporelle après traduction
        int binary_tram_size = 1; // taille actuelle de la trame temporelle en fonction de la lettre en morse
    private:
        void tram_fill(bool tram[], int tram_size); // Permet de remplir la trame temporelle finale (binary_tram) avec les partie de trame ci dessous
        bool tram_short[2] = {1, 0}; // Partie de trame temporelle pour un point en morse (reste allumé durant 1 période)
        bool tram_long[4] = {1, 1, 1, 0}; // Partie de trame temporelle pour un trait en morse (reste allumé durant 3 périodes)
};

#endif