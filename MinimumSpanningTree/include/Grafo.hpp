#ifndef GRAFO
#define GRAFO
#include <vector>
#include <iostream>
#include <list>
#include "Loja.hpp"
using namespace std;
//Cria um par de id do vertice e peso da aresta
typedef pair<int, double> edj;
typedef pair<double, int> edjInv;
//Cria um struct auxiliar para guardar o menor percurso
struct Percurso {
    int saida = 0;
    int entrada = 0;
    double distancia = INFINITY;
};
class Grafo {
  public:
    Grafo(int numVertices, int maxM, int numDrones, int cosM, int cosC);
    void addLoja(Loja l);
    void imprimeTotal();
  private:
    vector<edj> *viz;
    vector<Loja> lojas;
    int numDrones;
    int maxM;
    int cosM;
    int cosC;
    int numVertices = 0;
    //Ordena e faz a substituicao no melhor percurso de acordo com o numero de drones disponíveis
    vector<Percurso> reorganiza(vector<Percurso> percursos);
    //Usa o algoritmo de Prim para obter uma Arvore Geradora Minima
    vector<Percurso> mst();
};

#endif
