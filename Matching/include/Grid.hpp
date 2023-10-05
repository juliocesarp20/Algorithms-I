#ifndef GRID
#define GRID
#include "Loja.hpp"
#include "Cliente.hpp"
#include "LojaClientes.hpp"

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Grid {
  public:
    //Cria um grid de tamanho NxM
    Grid(int N, int M);
    void setN(int N);
    void setM(int M);
    void addCliente(Cliente c);
    void addLoja(Loja l);
    int getM();
    int getN();
    //Retorna todos clientes
    deque<Cliente> getClientes();
    //Retorna todas lojas com seus clientes alocados
    deque<LojaClientes> getLojaClientes();
    int menorDistancia(Loja l, Cliente c);
    //Faz a alocacao estavel dos clientes nas lojas
    void match();
    //Imprime as lojas e seus clientes alocados
    void print();
  private:
    int N;
    int M;
    deque<Cliente> clientes;
    deque<LojaClientes> lojaClientes; 
    deque<deque<int>> grid;
    //Adiciona as lojas aos clientes pela ordem de preferencia
    void alocarClientesLoja();
    //Retorna o estoque total das lojas
    int estoque();
    //Retorna, se o Cliente c para uma determinada loja tem preferencia sobre os clientes ja alocados, o Id do cliente
    //sobre o qual ele tem a preferencia e -1 se nao tiver
    int preferencial(Cliente c,int cl);
    
};

#endif