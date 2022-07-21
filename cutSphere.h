#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class cutSphere : public Figurageometrica{
    int xcenter, ycenter, zcenter, radius;
    public:
        cutSphere(int xcenter, int ycenter, int zcenter, int radius);
        ~cutSphere(){};
        void draw(Sculptor &s);

};

#endif
