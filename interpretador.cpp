#include <fstream>
#include <sstream>
#include <iostream>
#include "interpretador.h"
#include "putVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "cutVoxel.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"

using namespace std;

Interpretador :: Interpretador(){}


  vector <Figurageometrica*> Interpretador :: parse(string filename){
  vector<Figurageometrica*> fig;
  stringstream ss;
  string token, s;
  ifstream fin;

  fin.open(filename.c_str());
  if (!fin.is_open()){
    cout<<"Problema ao abrir arquivo!\n"<< filename<< std::endl;
    exit(0);
  }

    while (fin.good()){
        getline(fin,s);
        if(fin.good()){
            ss.clear();
            ss.str(s);
            ss >> token;

            if(ss.good()){
                if(token.compare("dim")== 0){
                    ss >> dimx >> dimy >> dimz;
                }

                else if(token.compare("putVoxel")== 0){
                    int x, y, z;
                    ss >> x >> y >> z >> r >> b >>g >> a;
                    fig.push_back(new putVoxel(x,y,z,r,b,g,a));
                }

                else if(token.compare("cutVoxel")== 0){
                    int x, y, z;
                    ss >> x >> y >> z;
                    fig.push_back(new cutVoxel(x,y,z));
                }

                else if(token.compare("putBox")== 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> b >>g >> a;
                    fig.push_back(new putBox(x0, x1, y0, y1, z0, z1,r,b,g,a));
                }

                else if(token.compare("cutBox")== 0){
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                    fig.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
                }

                else if(token.compare("putSphere")== 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius >> r >> b >>g >> a;
                    fig.push_back(new putSphere(xcenter, ycenter, zcenter, radius,r,b,g,a));
                }

                else if(token.compare("cutSphere")== 0){
                    int xcenter, ycenter, zcenter, radius;
                    ss >> xcenter >> ycenter >> zcenter >> radius;
                    fig.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
                  }
                else if(token.compare("putEllipsoid")== 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> b >>g >> a;
                    fig.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r,b,g,a));
                }

                else if(token.compare("cutEllipsoid")== 0){
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
                    fig.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
                }
            }
        }
    }
    return(fig);
}

    int Interpretador::getdimx(){
    return dimx;
    }
    int Interpretador::getdimy(){
    return dimy;
    }
    int Interpretador::getdimz(){
    return dimz;
    }
