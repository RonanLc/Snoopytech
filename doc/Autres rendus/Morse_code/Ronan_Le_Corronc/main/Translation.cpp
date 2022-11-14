#include "Arduino.h"
#include "Translation.h"
#include "LettreMorse.h"

Translation::Translation(){};


void Translation::binaryMorse(const char* morse){

  binary_tram_size = 1;
    
  for(int i = 0; true; i++) {

    if(morse[i] == '.'){tram_fill(tram_short, sizeof(tram_short));} // Remplit la trame finale avec la partie de trame du point

    if(morse[i] == '-'){tram_fill(tram_long, sizeof(tram_long));} // Remplit la trame finale avec la partie de trame du trait

    if(morse[i] == NULL){break;} // Termine la commande lorsque la liste de morse est terminée
  }

}


void Translation::tram_fill(bool tram[], int tram_size){

  for(int i = 0; i < tram_size; i++){
    
    binary_tram[binary_tram_size+i] = tram[i]; // Ajoute la partie de trame à la trame finale
  }

  binary_tram_size += tram_size; // Agrandit la taille de la trame finale utilisé

}