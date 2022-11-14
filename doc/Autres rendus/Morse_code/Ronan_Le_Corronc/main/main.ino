#include "Arduino.h"
#include "LettreMorse.h"
#include "Translation.h"

const int blinkSpeed = 200; // Correspond à la durée des périodes de la LED (passage entre éteint et allumé)
int incomingByte;

LettreMorse lm;
Translation tr;


void setup() {

  Serial.begin(9600);

}


void loop() {

  if (Serial.available() > 0) {
    
    incomingByte = Serial.read();

    lm.morseConverter(incomingByte); // Convertit la lettre reçu en morse

    tr.binaryMorse(lm.morse); // Convertit le morse en trame temporelle de 0 et 1 (correspondant à l'état de la LED au fil du temps)
    Serial.println(lm.morse);

    for(int i = 0; i < tr.binary_tram_size; i++){
      delay(blinkSpeed);
      digitalWrite(LED_BUILTIN, tr.binary_tram[i]); // Affiche l'état de la LED indiqué dans la trame temporelle finale.
    }

    delay(blinkSpeed*2); // Pause entre chaque LED
  }
}