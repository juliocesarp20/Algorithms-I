#ifndef CLIENTE
#define CLIENTE

#include "Loja.hpp"
#include <iostream>
#include <algorithm>


using namespace std;

class Cliente {
  public:
    Cliente(int id, int idade, string estado, string tipoPgto,int locX,int locY);
    Cliente();
    void setId(int id);
    void setEstado(string estado);
    void setIdade(int idade);
    void setTipoPgto(string tipoPgto);
    void setLocX(int locX);
    void setLocY(int locY);
    //Retorna as lojas em ordem de preferencia
    deque<Loja> getLojas();
    //Adiciona uma loja em ordem de preferencia
    void addLoja(Loja l);
    int getId();
    string getEstado();
    int getIdade();
    string getTipoPgto();
    int getLocX();
    int getLocY();
    double getTicket();
    //Calcula a menor distancia entre uma loja e um cliente
    int menorDistancia(Loja l, Cliente *c);
    void deleteLoja();
  private:
    int id;
    int idade;
    string estado;
    string tipoPgto;
    int locX;
    int locY;
    double ticket;
    int scoreEstado(string estado);
    int scorePgto(string tipoPgto);
    deque<Loja> lojas;
    //Funcao auxiliar no calculo da distancia
    double distancia(int x1, int y1, int x2, int y2);
   
};

#endif