#include "Sculptor.h" //Inclusão de declaração de classe
#include <iostream> //Inclusão das funções de entrada e saida
#include <cmath> //Inclusão das funções matemáticas
#include <fstream> //Inclusão de fluxo para arquivos
#include <stdlib.h> //Inclusão da função exit
#include <iomanip> //Inclusão da manipulação da formatação de saída dos inteiros


using namespace std;

Sculptor :: Sculptor (int _nx, int _ny, int _nz){

//Atribuição dos valores aos métodos protect
nx= _nx; //Dimensão x da matriz
ny= _ny; //Dimensão y da matriz
nz= _nz; //Dimensão z da matriz

r = 0; //Definição da cor Red para cada voxel
g = 0; //Definição da cor Green para cada voxel
b = 0; //Definição da cor Blue para cada voxel
a = 0; //Definição da Transparência para cada voxel

//Implementação da alocação dinâmica de memória
  v = new Voxel**[_nx]; //1º dimensão da matriz: aloca nx blocos do tipo voxel
  for(int i=0; i<nx; i++){
    v[i]  = new Voxel*[_ny]; //2º dimensão da matriz: aloca ny blocos do tipo voxel
    for(int j=0; j<ny; j++){
      v[i][j]= new Voxel[_nz]; //3º dimensão da matriz: aloca nz blocos do tipo voxel

    }
  }
   for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        this -> v[i][j][k].r = this -> r;
        this -> v[i][j][k].g = this -> g;
        this -> v[i][j][k].b = this -> b;
        this -> v[i][j][k].a = this -> a;
        this -> v[i][j][k].isOn = false;
        //Inicialização de cada voxel para cada membro da struct
      }
    }
  }
}

/**
*
*@brief função destrutora da matriz
*@param int _nx, int _ny, int _nz
*/

//Implementação do destrutor de classe
Sculptor :: ~Sculptor(){
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      delete []  v[i][j]; //Libera a última sequência alocada
    }
    delete [] v[i]; //Libera a penúltima sequência alocada
  }
  delete [] v; //Libera a primeira sequência alocada
}

/**
*
*@brief função para colorir os voxels
*@param float r, float g, float b, float alpha
*/
//Implementação do membro de seleção de cor de voxel
void Sculptor:: setColor(float r, float g, float b, float alpha){
  this -> r = r;
  this -> g = g;
  this -> b = b;
  this -> a = alpha;
  //Atribui cores e transparência de acordo com os parâmetros

}
/**
*
*@brief função de ativação voxels
*@param int x, int y, int z
*/
//Implementação do membro de ativação de voxel
void Sculptor:: putVoxel(int x, int y, int z){
  this -> v[x][y][z].r = this -> r;
  this -> v[x][y][z].g = this -> g;
  this -> v[x][y][z].b = this -> b;
  this -> v[x][y][z].a = this -> a;
  this -> v[x][y][z].isOn = true;
  //Ativa o voxel e atribui a ele a cor atual se a posição for válida

}

/**
*
*@brief função de desativação de voxels
*@param int x, int y, int z
*/
//Implementação do membro de desativação de voxel
void Sculptor:: cutVoxel(int x, int y, int z){
  this -> v[x][y][z].isOn = false;
  //Desativa o voxel se a posição for válida

}

/**
*
*@brief função de ativação de um bloco voxels
*@param int x0, int x1, int y0, int y1, int z0, int z1
*/
//Implementação do membro de ativação do bloco de voxels
void Sculptor:: putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  if ((this -> nx >= x0 && this -> nx >= x1) && (this -> ny >= y0 && this -> ny >= y1) && (this -> nz >= z0 && this -> nz >= z1)){
    for(int i = x0; i < x1; i++){
      for(int j =  y0; j < y1; j++){
        for (int k = z0; k < z1; k++){
          this -> v[i][j][k].r = this -> r;
          this -> v[i][j][k].g = this -> g;
          this -> v[i][j][k].b = this -> b;
          this -> v[i][j][k].a = this -> a;
          this -> v[i][j][k].isOn = true;
          //Ativa um bloco de voxels e atribui a eles a cor atual se a posição for válida
        }
      }
    }
  }
}

/**
*
*@brief função de desativação de um bloco voxels
*@param int x0, int x1, int y0, int y1, int z0, int z1
*/

//Implementação do membro de desativação do bloco de voxels
void Sculptor:: cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  if ((this -> nx >= x0 && this -> nx >= x1) && (this -> ny >= y0 && this -> ny >= y1) && (this -> nz >= z0 && this -> nz >= z1)){
    for(int i = x0; i < x1; i++){
      for(int j = y0; j < y1; j++){
        for (int k = z0; k < z1; k++){
          this -> v[i][j][k].isOn = false;
          //Desativa um bloco de voxels se a posições forem válidas
        }
      }
    }
  }
}
/**
*
*@brief função de ativação de uma esfera
*@param int xcenter, int ycenter, int zcenter, int radius
*/
//Implementação do membro de ativação de esfera
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < ny; j++){
      for (int k = 0; k <nz; k++){
        if ((pow(i-xcenter,2)) + (pow(j-ycenter,2)) + (pow(k-zcenter,2)) <= (pow(radius,2))){
          this -> v[i][j][k].r = this -> r;
          this -> v[i][j][k].g = this -> g;
          this -> v[i][j][k].b = this -> b;
          this -> v[i][j][k].a = this -> a;
          this -> v[i][j][k].isOn = true;
          //Ativa um bloco de voxels e atribui a eles a cor atual se a condição for satisfeita
        }
      }
    }
  }
}

/**
*
*@brief função de desativação de uma esfera
*@param int xcenter, int ycenter, int zcenter, int radius
*/
//Implementação do membro de desativação de esfera
void Sculptor ::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        if ((pow(i-xcenter,2)) + (pow(j-ycenter,2)) + (pow(k-zcenter,2)) <= (pow(radius,2))){
         this -> v[i][j][k].isOn = false;
         //Desativa um bloco de voxels e atribui a eles a cor atual se a condição for satisfeita
        }
      }
    }
  }
}

/**
*
*@brief função de ativação de uma elipsoide
*@param int xcenter, int ycenter, int zcenter, int rx, int ry, int rz
*/
//Implementação do membro de ativação de elipsoide
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        if ((pow(i-xcenter,2)/pow (rx,2)) + (pow(j-ycenter,2)/pow (ry,2)) + (pow(k-zcenter,2)/pow (rz,2)) <= 1){
          this -> v[i][j][k].r = this -> r;
          this -> v[i][j][k].g = this -> g;
          this -> v[i][j][k].b = this -> b;
          this -> v[i][j][k].a = this -> a;
          this -> v[i][j][k].isOn = true;
          //Ativa um bloco de voxels e atribui a eles a cor atual se a condição for satisfeita
        }
      }
    }
  }
}
/**
*
*@brief função de desativação de uma elipsoide
*@param int xcenter, int ycenter, int zcenter, int rx, int ry, int rz
*/
//Implementação do membro de desativação de elipsoide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
   for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        if ((pow(i-xcenter,2)/pow (rx,2)) + (pow(j-ycenter,2)/pow (ry,2)) + (pow(k-zcenter,2)/pow (rz,2)) <= 1){
          this -> v[i][j][k].isOn = false;
          //Desativa um bloco de voxels e atribui a eles a cor atual se a condição for satisfeita
        }
      }
    }
  }
}
/**
*
*@brief função de gravar o arquivo
*@param
*/
//Implementação do membro de gravação de arquivo
void Sculptor:: writeOFF(char* filename){
int voxeltot = 0, contvoxel = 0; //Contadores dos vertices e interação

  ofstream arq; //Objeto para fluxo de saída
  arq.open(filename); //Abertura do fluxo para arquivo
  arq << setprecision (2);

   for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        if (v[i][j][k].isOn == true){
          voxeltot ++;
          //Guarda o número de voxels ativadas
        }
      }
    }
  }

  arq << "OFF\n"; //Escreve no arquivo o tipo de arquivo
  arq << 8 * voxeltot << " " << 6 * voxeltot << " " << "0" << endl;

  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        if (this ->v[i][j][k].isOn == true){

          arq << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 <<  endl;
          arq << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 <<  endl;
          arq << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 <<  endl;
          arq << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 <<  endl;
          arq << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 <<  endl;
          arq << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 <<  endl;
          arq << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 <<  endl;
          arq << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 <<  endl;
        }
      }
    }
  } //Define as coordenadas dos vértices do cubo

  for(int i=0; i<nx; i++){
    for(int j=0; j<ny; j++){
      for (int k = 0; k<nz; k++){
        if (v[i][j][k].isOn == true){

          arq << "4"  << " " << 8* contvoxel + 0  << " " << 8* contvoxel + 3 << " " << 8* contvoxel + 2 << " " << 8* contvoxel + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          arq << "4"  << " " << 8* contvoxel + 4  << " " << 8* contvoxel + 5 << " " << 8* contvoxel + 6 << " " << 8* contvoxel + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          arq << "4"  << " " << 8* contvoxel + 0  << " " << 8* contvoxel + 1 << " " << 8* contvoxel + 5 << " " << 8* contvoxel + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          arq << "4"  << " " << 8* contvoxel + 0  << " " << 8* contvoxel + 4 << " " << 8* contvoxel + 7 << " " << 8* contvoxel + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          arq << "4"  << " " << 8* contvoxel + 3  << " " << 8* contvoxel + 7 << " " << 8* contvoxel + 6 << " " << 8* contvoxel + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
          arq << "4"  << " " << 8* contvoxel + 1  << " " << 8* contvoxel + 2 << " " << 8* contvoxel + 6 << " " << 8* contvoxel + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;

        contvoxel++;

        }
      }
    }
  } //Define número de vértices, referência dos vértices, cor e transparência de cadda face do voxel

  arq.close(); //Fecha o fluxo

}
