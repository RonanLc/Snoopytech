#include "LettreMorse.h"

LettreMorse::LettreMorse(){};

void LettreMorse::morseConverter(int letter){

  if(letter > 64 && letter < 91) {letter += 32;}

  switch (letter){
    case 'a':
        LettreMorse::morse = ".-";
        break;
    case 'b':
        LettreMorse::morse = "-...";
        break;
    case 'c':
        LettreMorse::morse = "-.-.";
        break;
    case 'd':
        LettreMorse::morse = "-..";
        break;
    case 'e':
        LettreMorse::morse = ".";
        break;
    case 'f':
        LettreMorse::morse = "..-.";
        break;
    case 'g':
        LettreMorse::morse = "--.";
        break;
    case 'h':
        LettreMorse::morse = "....";
        break;
    case 'i':
        LettreMorse::morse = "..";
        break;
    case 'j':
        LettreMorse::morse = ".---";
        break;
    case 'k':
        LettreMorse::morse = "-.-";
        break;
    case 'l':
        LettreMorse::morse = ".-..";
        break;
    case 'm':
        LettreMorse::morse = "--";
        break;
    case 'n':
        LettreMorse::morse = "-.";
        break;
    case 'o':
        LettreMorse::morse = "---";
        break;
    case 'p':
        LettreMorse::morse = ".--.";
        break;
    case 'q':
        LettreMorse::morse = "--.-";
        break;
    case 'r':
        LettreMorse::morse = ".-.";
        break;
    case 's':
        LettreMorse::morse = "...";
        break;
    case 't':
        LettreMorse::morse = "-";
        break;
    case 'u':
        LettreMorse::morse = "..-";
        break;
    case 'v':
        LettreMorse::morse = "...-";
        break;
    case 'w':
        LettreMorse::morse = ".--";
        break;
    case 'x':
        LettreMorse::morse = "-..-";
        break;
    case 'y':
        LettreMorse::morse = "-.--";
        break;
    case 'z':
        LettreMorse::morse = "--..";
        break;
    case '1':
        LettreMorse::morse = ".----";
        break;
    case '2':
        LettreMorse::morse = "..---";
        break;
    case '3':
        LettreMorse::morse = "...--";
        break;
    case '4':
        LettreMorse::morse = "....-";
        break;
    case '5':
        LettreMorse::morse = ".....";
        break;
    case '6':
        LettreMorse::morse = "-....";
        break;
    case '7':
        LettreMorse::morse = "--...";
        break;
    case '8':
        LettreMorse::morse = "---..";
        break;
    case '9':
        LettreMorse::morse = "----.";
        break;
    case '0':
        LettreMorse::morse = "-----";
        break;
    default:
        LettreMorse::morse = "";
        break;
    }

}