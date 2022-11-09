#include "Arduino.h"
#include "Translation.h"
#include "LettreMorse.h"

Translation::Translation(){};

bool tram_short[] = {0, 1};
bool tram_long[] = {0, 1, 1};

void Translation::binaryMorse(const char* morse){

  Serial.println(morse);
    
    for(int i = 0; i < sizeof(morse); i++) {
        
        if(morse[i] == '.'){Serial.print(" court");}






        if(morse[i] == '-'){Serial.print(" long");}
    }

}