#include <iostream>
#include "interpretador.h"
#include "Sculptor.h"
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"

int main(){
  Sculptor *mike;

  Interpretador parser;

  std::vector<Figurageometrica*> fig;
  fig = parser.parse("C:\\Users\\suzym\\Documents\\mikewazowski.txt");

  mike = new Sculptor(parser.getdimx(), parser.getdimy(), parser.getdimz());

  for(size_t i=0; i<fig.size(); i++){

    std::cout << "draw\n";

    fig[i]->draw(*mike);
  }

  mike->writeOFF("C:\\Users\\suzym\\Documents\\mikewazowski_saida.off");

  for(size_t i=0; i<fig.size(); i++){
    delete fig[i];
  }
  delete mike;
  return 0;
}
