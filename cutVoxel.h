#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "Figurageometrica.h"
#include "Sculptor.h"

class cutVoxel: public Figurageometrica
{
  int x, y, z;
  public:
    cutVoxel(int x, int y, int z);
    ~cutVoxel(){};
    void draw(Sculptor &s);
};

#endif
