#include <iostream>
#include "Grafo.hpp"

using namespace std;

//Lê o número de lojas, a quilometragem maxima das motos, o numero de drones e o custo de transporte por motos e caminhoes
int main(int argc, char *argv[])
{
     int i = 0;
    string linha;
    int N,K,D,M,C;
    //Le o tamanho do grid
    cin >> N >> K >> D >> M >> C;
    int cX;
    int cY;
    Loja l;
    Grafo g = Grafo(N, K, D, M, C);
    //Le todas as lojas e as adiciona no grafo
    while (i < N)
    {
        cin >> cX>>cY;
        l = Loja(cX,cY);
        g.addLoja(l);
        i++;
    }
    if (N != D) {
        g.imprimeTotal();
    }
    else {
        printf("%.3f %.3f", 0.0, 0.0);
    }
    return 0;
}
