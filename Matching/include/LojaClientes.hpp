#ifndef LOJACLIENTE
#define LOJACLIENTE

#include <iostream>
#include "Cliente.hpp"
using namespace std;

class LojaClientes {
  public:
    //Cria uma classe que armazena os clientes a loja a qual ele foi alocado
    LojaClientes(deque<Cliente> c, Loja loja);
    LojaClientes(Loja loja);
    void addCliente(Cliente c);
    deque<Cliente> getClientes();
    deque<int> getIds();
    void setLoja(Loja l);
    Loja getLoja();
    //Remove o primeiro cliente da estrutura
    void removeCliente();
    //Muda o estoque de uma loja
    void changeEstoque(int estoque);
    //Ordena os clientes pelo ticket e pelo Id
    void sort();
    private:
    deque<Cliente> clientes;
    deque<int> ids;
    Loja loja;
};

#endif