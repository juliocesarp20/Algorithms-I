#include "Loja.hpp"
int Loja::lojasId = 0;
Loja::Loja(){};
Loja::Loja(int locX,int locY){
    this->id=lojasId;
    lojasId++;
    this->locX=locX;
    this->locY=locY;
    this->drone = false;
}

void Loja::setLocX(int locX){
    this->locX=locX;
}
void Loja::setLocY(int locY){
    this->locY=locY;
}
int Loja::getId(){

    return id;
}
int Loja::getLocX(){
    return locX;
}
int Loja::getLocY(){
    return locY;
}

void Loja::setDrone(bool drone) {
    this->drone = drone;
}

bool Loja::getDrone() {
    return drone;
}

double Loja::getDistancia(Loja l){
    int x1,x2,y1,y2;
    x1 = getLocX();
    x2 = l.getLocX();
    y1 = getLocY();
    y2 = l.getLocY();
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
