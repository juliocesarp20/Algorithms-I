#include "Colheita.hpp"
#include <iostream>
using namespace std;

int main() {
    int numFileiras, numMacieiras;
    cin >> numFileiras >> numMacieiras;
    vector<vector<int>> pomar(numFileiras, vector<int>(numMacieiras, 0));
    for (int i = 0; i < numFileiras; i++) {
        for (int j = 0; j < numMacieiras; j++) {
            cin >> pomar[i][j];
        }
    }
    Colheita c = Colheita(numFileiras, numMacieiras, pomar);
    c.print();
    return 0;
} 