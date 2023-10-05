#ifndef COLHEITA
#define COLHEITA

#include <vector>
#include "iostream"

using namespace std;
//Cria uma colheita com fileiras, macieiras e um pomar ja completo
struct Colheitadeira {
    int maxi = 0;
    vector<int> indices;
};

class Colheita {
public:
    Colheita(int numFileiras, int numMacieiras,vector<vector<int>> pomar);
    void print();
    
private:
    int numFileiras;
    int numMacieiras;
    vector<int> indices(int cInicio);
    //Retorna o maior valor possivel para a colheita dada as restricoes de movimento usando programacao dinamica para somar os valores a cada linha
    Colheitadeira caminho();
    //Calcula os indices do caminho fazendo a rota inversa
    vector<vector<int>> pomar;

};

#endif
