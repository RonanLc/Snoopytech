#include <Servo.h>

// moteur 
Servo esc;
int pot;

const int pinPot = A0;
const int pinEsc = 5;

// capteur Hall vitesse
const int sonde_pin=2;

int compteur=0;
bool state=HIGH;

int vitesse; // tr/s
const int periode=50; // ms donne frequence d'echantillonage
const int poles=14; // nombre d'aimants sur le rotor 
const int diam=5; // cm diametre du rotor 
long timer1=0;

// reponse indicielle
const int declenchement = 1000;
long t0=1000;

void setup() {
  Serial.begin(115200);
  esc.attach(pinEsc, 1000, 3000);

  pinMode(sonde_pin,INPUT);

}

void loop() {

// on souhaite estimé le temps de réponse du moteur 
  if(millis()-t0 <= declenchement){
    esc.write(90);
  }

  if(millis()-t0 > declenchement){
    esc.write(180);
  }

// mesure de vitesse
  if (digitalRead(sonde_pin) != state){
    compteur++;
    state=!state;
  }

  if(millis()-timer1 > periode){
    speed();
    Serial.println(vitesse);
  }

// // debogage
//   Serial.print(millis());
//   Serial.print(",");

}

void speed(){
  vitesse=(compteur)/(poles*periode*0.001);
  compteur=0;
  timer1=millis();
}
