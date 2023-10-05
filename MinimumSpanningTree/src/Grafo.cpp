#include "Grafo.hpp"
#include <queue>
#include <algorithm>
Grafo::Grafo(int numVertices, int maxM, int numDrones,  int cosM, int cosC){
    this->maxM = maxM;
    this->numDrones = numDrones;
    this->cosM = cosM;
    this->cosC = cosC;
    viz = new vector<edj>[numVertices];

};

//Adiciona uma loja
void Grafo::addLoja(Loja l){
    numVertices++;
    int u, v;
    double d;
    for (Loja ls : lojas) {
        u = l.getId();
        v = ls.getId();
        d = l.getDistancia(ls);
        edj e2 = make_pair(v, d);
        edj e1 = make_pair(u, d);
        viz[u].push_back(e2);
        viz[v].push_back(e1);
    }
    lojas.push_back(l);

}
//Imprime o custo de se percorrer a menor distancia 
void Grafo::imprimeTotal() {
    vector<Percurso> perc = mst();
    double moto = 0;
    double caminhao = 0;
    perc=reorganiza(perc);
    for (int i = 1; i < numVertices; i++) {
        if (perc[i].distancia <= maxM) {
            moto += (perc[i].distancia*cosM);
        }
        else {
            caminhao += (perc[i].distancia*cosC);
        }
    }
    printf("%.3f %.3f", moto, caminhao);
}

//Retorna o percurso gerado pelo algoritmo de prim utilizando um queue de prioridades
vector<Percurso> Grafo::mst() {
    priority_queue< edjInv, vector <edjInv>, greater<edjInv>> v;
    vector<bool> adicionados(numVertices, false);
    vector<Percurso> percursos(numVertices);
    edjInv e1 = make_pair(0.0, 0);
    v.push(e1);
    percursos[0].distancia = 0.0;

    while (!v.empty()) {
        int val = v.top().second;
        v.pop();
        if (adicionados[val] == true) {
            continue;
        }
        adicionados[val] = true;
        vector<pair<int, double> >::iterator i;
        for (i = viz[val].begin(); i != viz[val].end(); i++)
        {
            int n = (*i).first;
            double valF = (*i).second;

            if (adicionados[n] == false && percursos[n].distancia > valF) {
                percursos[n].distancia = valF;
                edjInv aux = make_pair(percursos[n].distancia, n);
                v.push(aux);
                percursos[n].entrada = n;
                percursos[n].saida = val;
                percursos[n].distancia = valF;
            }

        }   
    }
    return percursos;
}

//Ordena um percurso e coloca os drones nas posições adequadas
vector<Percurso> Grafo::reorganiza(vector<Percurso> percursos) {
    sort(percursos.begin()+1, percursos.end(), [](const auto& p1, const auto& p2)
        {
            return p1.distancia > p2.distancia;
        });
    vector<edj>::iterator j;
    vector<int> aux;
    int k = 1;
    //Coloca 0 nas arestas de maior valor que representam as conexões de lojas com drones
    while (numDrones > 1) {
        percursos[k].distancia = 0;
        k++;
        numDrones--;
        }
    return percursos;
    }


