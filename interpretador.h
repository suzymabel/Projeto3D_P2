#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "Figurageometrica.h"

using namespace std;

class Interpretador {
  int dimx,dimy,dimz;
  float r, g, b, a;

  public:
    Interpretador();
    vector<Figurageometrica*> parse(string filename);
    int getdimx();
    int getdimy();
    int getdimz();

};

#endif
