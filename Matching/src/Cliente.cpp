#include "Cliente.hpp"

int Cliente::scoreEstado(string estado){
    if(estado=="MG"){
        return 0;
    }else if(estado=="PR"){
        return 10;
    }else if(estado=="SP"){
        return 20;
    }else if(estado=="SC"){
        return 30;
    }else if(estado=="RJ"){
        return 40;
    }else if(estado=="RN"){
        return 50;
    }else if(estado=="RS"){
        return 60;
    }else{
        return 0;
    }
}

int Cliente::scorePgto(string tipoPgto){
    if(tipoPgto=="DINHEIRO"){
        return 1;
    }else if(tipoPgto=="DEBITO"){
        return 2;
    }else if(tipoPgto=="CREDITO"){
        return 3;
    }else{
        return 1;
    }
}
Cliente::Cliente(){
    
}
Cliente::Cliente(int id, int idade, string estado, string tipoPgto,int locX,int locY){
    this->id=id;
    this->idade=idade;
    this->estado=estado;
    this->tipoPgto=tipoPgto;
    this->locX=locX;
    this->locY=locY;
    double spgto = scorePgto(tipoPgto);
    ticket = (abs(60-idade)+scoreEstado(estado))/spgto;
}
void Cliente::setId(int id){
    this->id=id;
}
void Cliente::setIdade(int idade){
    this->idade=idade;
}
void Cliente::setEstado(string estado){
    this->estado=estado;
}
void Cliente::setTipoPgto(string tipoPgto){
    this->tipoPgto=tipoPgto;
}
void Cliente::setLocX(int locX){
    this->locX=locX;
}
void Cliente::setLocY(int locY){
    this->locY=locY;
}

int Cliente::getId(){
    return id;
}
int Cliente::getIdade(){
    return idade;
}
string Cliente::getEstado(){
    return estado;
}
string Cliente::getTipoPgto(){
    return tipoPgto;
}
int Cliente::getLocX(){
    return locX;
}
int Cliente::getLocY(){
    return locY;
}
double Cliente::getTicket(){
    return ticket;
}
deque<Loja> Cliente::getLojas(){
    return lojas;
}


double Cliente::distancia(int x1, int y1, int x2, int y2) {
    int maix;
    int menx;
    int maiy;
    int meny;
    if (x2 >= x1) {
        maix = x2;
        menx = x1;
    }
    else {
        maix = x1;
        menx = x2;
    }
    if (y2 >= y1) {
        maiy = y2;
        meny = y1;
    }
    else {
        maiy = y1;
        meny = y2;
    }

    return std::max(abs(maix - menx),abs(maiy - meny));
}

int Cliente::menorDistancia(Loja l, Cliente *c){
    double d = distancia(c->getLocX(), c->getLocY(), l.getLocX(), l.getLocY());
    if (d > 0) {
        return d - 1;
    }
    return d;
};

void Cliente::addLoja(Loja l){
    auto it = lojas.begin();
    bool insert=false;
    for(std::size_t i=0;i<lojas.size();i++){
        if(menorDistancia(l,this)<menorDistancia(lojas.at(i),this)){
             it = lojas.insert(lojas.begin() + i, l);
             
                insert=true;
                break;
        }else if(menorDistancia(l,this)==menorDistancia(lojas.at(i),this)){
                    int aux = -1;
                    for (std::size_t j = i; j < lojas.size(); j++) {
                        if (l.getId() < lojas.at(j).getId()) {
                            aux = j;
                        }
                    }
                    if (aux != -1) {
                        cout << aux;
                        it = lojas.insert(lojas.begin() + aux, l);
                        insert = true;
                        break;
                    }
                }

        }
    if(!insert){
    lojas.push_back(l);
    }
}

void Cliente::deleteLoja(){
    lojas.pop_front();
}
