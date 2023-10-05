#include "Loja.hpp"
Loja::Loja(){};
Loja::Loja(int id, int estoque,int locX,int locY){
    this->id=id;
    this->estoque=estoque;
    this->locX=locX;
    this->locY=locY;
    this->total=estoque+0;
}
void Loja::setId(int id){
    this->id=id;
}
void Loja::setEstoque(int estoque){
    this->estoque=estoque;
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
int Loja::getEstoque(){
    return estoque;
}
int Loja::getTotal(){
    return total;
}
int Loja::getLocX(){
    return locX;
}
int Loja::getLocY(){
    return locY;
}

