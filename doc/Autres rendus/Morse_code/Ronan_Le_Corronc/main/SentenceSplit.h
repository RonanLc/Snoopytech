#ifndef SRC_SENTENCE_SPLIT_H_
#define SRC_SENTENCE_SPLIT_H_

/**
 * Cette classe regroupe tous les éléments pour découper la phrase en lettre indépendante
 * 
 * Elle regroupe 3 fonctions utilisables
 */
class SentenceSplit {
    public:
      SentenceSplit();
      void initialisation(const char* phs);
      int read();
      int available();
      int cursor = -1;      // Curseur permettant de lire lettre par lettre la phrase à découper
    private:
      const char* phrase;   // Variable stockant la phrase
      int size;             // variable indiquant la taille totale de la phrase
};

#endif