#ifndef SRC_TRANSLATION_H_
#define SRC_TRANSLATION_H_

/**
 * Cette classe regroupe tous les éléments pour traduire le morse en une trame temporelle binaire (correspondant à l'état de la LED au fil du temps)
 * 
 * Elle regroupe 1 fonction utilisable
 */
class Translation {
    public:
        Translation();
        void binaryMorse(const char* morse);
        bool binary_tram[21] = {0};                 // trame finale après traduction
        int binary_tram_size = 1;                   // taille actuelle de la trame temporelle en fonction de la lettre en morse
    private:
        void tram_fill(bool tram[], int tram_size);     // Permet de remplir la trame temporelle finale (binary_tram) avec les partie de trame ci dessous
        bool tram_short[2] = {1, 0};                    // Partie de trame temporelle pour un point en morse (reste allumé durant 1 période)
        bool tram_long[4]  = {1, 1, 1, 0};              // Partie de trame temporelle pour un trait en morse (reste allumé durant 3 périodes)
        bool tram_end[3]   = {0, 0, 0};                 // Pause entre chaque lettres (3 périodes)
        bool tram_space[7] = {0, 0, 0, 0, 0, 0, 0};     // Pause entre chaque mots (7 périodes)
};

#endif