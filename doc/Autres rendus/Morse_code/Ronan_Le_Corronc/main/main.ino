/*

  ########  Développé par Ronan Le Corronc  #######
  ###  Étudiant en ROB3 à Polytech Nice-Sophia  ###
  ################  Novembre 2022  ################


Ce programme permet d'afficher, à l'aide d'une LED sur une carte arduino, une phrase traduite en morse.

Il est composé de 7 sous fichiers, sans lesquels le code risque de ne pas fonctionner :
  - main.ino
  - LettreMorse.h
  - LettreMorse.cpp
  - Translation.h
  - Translation.cpp
  - SentenceSplit.h
  - SentenceSplit.cpp

Le programme fonctionne de la façon suivante :

  - Il enregistre la phrase à traduire (ligne 46)

  - Il récupère une seule lettre de la phrase

  - Il traduit la lettre en morse

  - Il traduit le morse en une trame temporelle binaire correspondant à l'état de la LED au fil du temps
    (par exemple,   en morse, le A = .-   / la trame temporelle sera donc : 0101110)
    (autre exemple, en morse, le F = ..-. / la trame temporelle sera donc : 01010111010)

  - Il active la LED en fonction de la trame temporelle sans "bloquer" le programme grace à la fonction millis()

  - Il retourne chercher récupérer la lettre suivante de la phrase (ligne 22)
*/


#include "Arduino.h"
#include "LettreMorse.h"
#include "Translation.h"
#include "SentenceSplit.h"

LettreMorse lm;
Translation tr;
SentenceSplit ss;

const char* phrase = "Veuillez entrer une phrase à traduire...";    // Phrase à afficher en morse     <--------- ############### VALEUR A MODIFIER ###############

const int blinkSpeed = 200;         // Correspond à la durée des périodes de la LED (passage entre éteint et allumé)
int tramCursor;                     // tramCursor permet de venir lire, caractère par caractère, la trame temporelle correspondant à l'affiche en morse sur la LED. IL fonctionne comme un curseur dans une trame de valeur


void setup() {

  Serial.begin(9600);               // Initialise la communication en série entre l'ordinateur et la carte Arduino
  Serial.println("Starting...");

  pinMode(LED_BUILTIN, OUTPUT);     // Initialise la LED
  ss.initialisation(phrase);        // Initialise la phrase à traduire

}


void loop() {

  if (ss.available() > 0 && tramCursor >= tr.binary_tram_size) {    // Boucle permettant de traduire une lettre en morse, elle sera utilisé pour chaque lettre de la phrase  /  (Tant qu'il reste des lettres à lire  &&  Une fois que la trame précédente à entièrement été lu )

    tramCursor = 0;                   // Remet le curseur au début de la trame

    lm.morseConverter(ss.read());     // Convertit la lettre reçu en morse

    tr.binaryMorse(lm.morse);         // Convertit le morse en trame temporelle binaire (correspondant à l'état de la LED au fil du temps)

    Serial.print(phrase[ss.cursor]);  // Indique sur le moniteur la lettre affichée en morse
    Serial.print(" : ");
    Serial.println(lm.morse);         // Indique sur le moniteur la traduction en morse de la lettre

  }

  if (millis()%blinkSpeed < 1 && tramCursor < tr.binary_tram_size){   // Boucle permettant d'afficher le morse sur la LED sans "bloquer" le programme et la carte arduino  /  (  &&  Tant que toute la trame n'a pas été lu )

    digitalWrite(LED_BUILTIN, tr.binary_tram[tramCursor]);    // Allume ou éteint la LED
    tramCursor++;                                             // Déplace le curseur au caractère suivant

  }
  
  delay(1);   // limite la vitesse de répétition de la boucle loop()
}