#include "Arduino.h"
#include "SentenceSplit.h"

/**
 * Constructeur
*/
SentenceSplit::SentenceSplit(){};


/**
 * Cette fonction sert à enregistrer la phrase à traduire et définir
 * sa longueur pour l'utiliser plus tard dans la classe
 * 
 * Arguments (const char*): Phrase à traduire en morse
 * Return:
*/
void SentenceSplit::initialisation(const char* phs){

  phrase = phs;                               // Enregistre la phrase à traduire
  while (phrase[size] != NULL) { size++; }    // la fonction sizeof() ne fonctionne pas pour se type de variable alors cette boucle permet de connaitre la longueur de la phrase.

}


/**
 * Cette fonction fonctionne exactement comme la fonction read() de la classe Serial
 * elle permet, à chaque fois qu'elle est appelée, de renvoyer une nouvelle lettre d'une phrase dans l'ordre
 * 
 * Arguments:
 * Return (int): La prochaine lettre de la phrase à afficher
*/
int SentenceSplit::read(){

  cursor++;                 // décale à la lettre suivant le curseur servant à lire la phrase
  return phrase[cursor]; 

}


/**
 * Cette fonction fonctionne exactement comme la fonction available() de la classe Serial
 * elle permet de renvoyer le nombre de lettre qui reste à lire dans la phrase  
 * 
 * Arguments:
 * Return (int): Le nombre de lettre restant à afficher
*/
int SentenceSplit::available(){

  return (size-1-cursor);   // size:   correspond à la taille totale de la phrase
                            // cursor: correspond à la position actuelle de la lecture de la phrase
                            // le cursor commencant à 0 pour afficher la première lettre, il faut ajouter -1 pour mettre size et cursor sur la meme base
}
