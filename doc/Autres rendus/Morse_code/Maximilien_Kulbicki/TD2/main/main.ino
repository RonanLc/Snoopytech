#include "Traducteur.hpp"

const int led = LED_BUILTIN;
const char sos[90]="OU est l'érreur?";

Traducteur mot(sos,led);

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);

    Serial.print("Mot de départ: ");
    Serial.println(sos);
    Serial.print("Traduction: ");
    Serial.println(mot.get_sequence());
    
}

void loop() {
    mot.clignotements();

}