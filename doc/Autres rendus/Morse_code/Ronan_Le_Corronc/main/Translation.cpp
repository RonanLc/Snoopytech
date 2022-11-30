#include "Arduino.h"
#include "Translation.h"
#include "LettreMorse.h"

/**
 * Constructeur
*/
Translation::Translation(){};

/**
 * Cette fonction permet de convertir un caractère en morse en trame temporelle binaire (correspondant à l'état de la LED au fil du temps)
 * Pour ce faire la fonction vient assembler des trames pré-enregistrées bout à bout pour composer une trame entière
 * 
 * Arguments (const char*): Traduction en morse de la lettre
 * Return:
*/
void Translation::binaryMorse(const char* morse){

  binary_tram_size = 1;                                           // Initialise la taille de la trame finale
    
  for(int i = 0; true; i++) {                                     // Se repete en fonction du nombre de caractère dans la traduction en morse

    if(morse[i] == '.'){tram_fill(tram_short, sizeof(tram_short));}   // Remplit la trame finale avec la partie de trame du point

    if(morse[i] == '-'){tram_fill(tram_long, sizeof(tram_long));}     // Remplit la trame finale avec la partie de trame du trait

    if(morse[i] == ' '){tram_fill(tram_space, sizeof(tram_space));}   // Remplit la trame finale avec la partie de trame de l'espace

    if(morse[i] == NULL){tram_fill(tram_end, sizeof(tram_end));       // Indique une fin dans la trame
                         break;}                                      // Termine la commande lorsque la liste de morse est terminée
  }

}


/**
 * Cette fonction permet d'assembler les trames pré-enregistrées bout à bout pour composer une trame entière
 * 
 * Arguments (bool[], int): trame pré-enregistrée, taille de la trame pré-enregistrée
 * Return:
*/
void Translation::tram_fill(bool tram[], int tram_size){

  for(int i = 0; i < tram_size; i++){           // Vient ajouter la trame pré-enregistrée à la trame finale caractère par caractère
    
    binary_tram[binary_tram_size+i] = tram[i];      // Ajoute un caractère de la trame pré-enregistrée à la trame finale
  }

  binary_tram_size += tram_size;                    // Indique la nouvelle taille de la trame finale

}