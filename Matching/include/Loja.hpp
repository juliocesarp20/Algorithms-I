#ifndef LOJA
#define LOJA
#include <deque>
#include <iostream>

using namespace std;

class Loja {
  public:
    Loja();
    Loja(int id, int estoque,int locX,int locY);
    void setId(int id);
    void setEstoque(int estoque);
    void setLocX(int locX);
    void setLocY(int locY);
    int getId();
    //Retorna o estoque atual da loja
    int getEstoque();
    int getLocX();
    int getLocY();
    //Retorna o estoque inicial da loja
    int getTotal();
  private:
    int id;
    int estoque;
    int locX;
    int locY;
    int total;
};

#endif