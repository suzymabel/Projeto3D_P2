#ifndef CUTBOX_H
#define CUTBOX_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class cutBox : public Figurageometrica{
  int x0, x1, y0, y1, z0, z1;
  public:
  cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ~cutBox(){};
  void draw(Sculptor &s);
};
#endif
