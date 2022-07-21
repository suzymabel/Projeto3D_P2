#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class putSphere: public Figurageometrica
{
  int xcenter, ycenter, zcenter, radius;
  public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~putSphere(){};
    void draw(Sculptor &s);
};
#endif
