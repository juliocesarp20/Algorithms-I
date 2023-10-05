#ifndef LOJA
#define LOJA
#include<math.h>
#include <iostream>

using namespace std;
class Loja {
  public:
    Loja();
    Loja(int locX,int locY);
    void setLocX(int locX);
    void setLocY(int locY);
    int getId();
    int getLocX();
    int getLocY();
    void setDrone(bool drone);
    bool getDrone();
    //Retorna a distância euclidiana entre a loja e outra loja l
    double getDistancia(Loja l);
  private:
    static int lojasId;
    int id;
    int locX;
    int locY;
    bool drone;
};

#endif