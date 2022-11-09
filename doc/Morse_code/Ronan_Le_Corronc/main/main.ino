#include "LettreMorse.h"
#include "Translation.h"

int incomingByte;
const int led = 13;

LettreMorse lm;
Translation tr;

void setup() {

  Serial.begin(9600);
  digitalWrite(led, 1);

}

void loop() {

  if (Serial.available() > 0) {

    incomingByte = Serial.read();
    Serial.println(incomingByte);

    lm.morseConverter(incomingByte);

    Serial.println(sizeof(lm.morse));
    tr.binaryMorse(lm.morse);

  }
}