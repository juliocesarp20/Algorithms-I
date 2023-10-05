#include <iostream>
#include <fstream>
#include <sstream>

#include "Grid.hpp"

using namespace std;

struct ArquivoNaoEncontradoException
{
};

int main(int argc, char *argv[])
{
    int i = 0;
    string linha;
    int M,N;
    int m;
    //Le o tamanho do grid
    cin >> M >> N;
    cin >> m;
    int id = 0;
    int estoque;
    int cX;
    int cY;
    Loja l;
    Grid g = Grid(M,N);
    //Le todas as lojas
    while (i < m)
    {
        cin >> estoque>>cX>>cY;
        l = Loja(id,estoque,cX,cY);
        g.addLoja(l);
        id++;
        i++;
    }
    i=0;
    id=0;
    int numClientes;
    int idade;
    string estado;
    string tpPgto;
    int ccX;
    int ccY;
    cin >> numClientes;
    Cliente c;
    //Le todos os clientes
    while (i < numClientes)
    {
        cin >> idade >> estado >> tpPgto >> ccX >> ccY;
        c = Cliente(id,idade,estado,tpPgto,ccX,ccY);
        g.addCliente(c);
        id++;
        i++;
    }
    
    //Chama o procedimento que conecta os clientes as lojas e os imprime
    g.match();
    //Imprime as conexoes
    g.print();

    return 0;
}
