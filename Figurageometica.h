#ifndef FIGURAGEOMETRICA_H_INCLUED
#define FIGURAGEOMETRICA_H_INCLUED
#include "Sculptor.h"

class Figurageometrica {
protected:
    float r, g, b, a;

public:
    virtual ~Figurageometrica(){};
    virtual void draw(Sculptor &s)=0;
};

#endif
