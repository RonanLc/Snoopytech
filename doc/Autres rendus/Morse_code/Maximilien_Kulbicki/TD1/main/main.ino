#include "Traducteur.hpp"

const int led = LED_BUILTIN;
const char sos[13]="robotique";

Traducteur* mot = new Traducteur(sos);

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);

    Serial.print("Mot de départ: ");
    Serial.println(sos);
    Serial.print("Traduction: ");
    Serial.println(mot->get_sequence());
    
}

void loop() {
    mot->clignotements(led);

}