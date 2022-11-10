#ifndef SRC_TRANSLATION_H_
#define SRC_TRANSLATION_H_

class Translation {
    public:
        Translation();
        void binaryMorse(const char* morse);
        bool binary[10];
        const char* morse;

    private:
};

#endif