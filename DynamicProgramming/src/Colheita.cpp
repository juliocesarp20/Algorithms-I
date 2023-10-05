#include "Colheita.hpp"

Colheita::Colheita(int numFileiras, int numMacieiras,vector<vector<int>> pomar) {
    this->numFileiras = numFileiras;
    this->numMacieiras = numMacieiras;
    this->pomar = pomar;
}


Colheitadeira Colheita::caminho()
{
    for (int i = 1; i < numFileiras; i++)
    {
        for (int j = 0; j < numMacieiras; j++)
        {
            if (j > 0 && j < numMacieiras - 1) {
                pomar[i][j] += max(max(pomar[i - 1][j - 1],pomar[i - 1][j]), pomar[i - 1][j + 1]);
            }

            else if (j < numMacieiras - 1) {
                pomar[i][j] += max(pomar[i - 1][j + 1],pomar[i - 1][j]);
            }
            
            else if (j > 0) {
                pomar[i][j] += max(pomar[i - 1][j - 1],pomar[i - 1][j]);
            }
        }
    }

    int maxi = 0;
    int cmaxi = 0;
    for (int j = 0; j < numMacieiras; j++) {
        if (pomar[numFileiras - 1][j] > maxi) {
            maxi = pomar[numFileiras - 1][j];
            cmaxi = j;
        }
    }
    Colheitadeira c = Colheitadeira();
    c.maxi = maxi;
    c.indices = indices(cmaxi);
    return c;
    
}

vector<int> Colheita::indices(int cInicio) {
    int maxt = 0;
    int maxdl = 0;
    int maxdr = 0;
    int c = cInicio;
    vector<int> ind;
    ind.push_back(c);
    for (int i = numFileiras - 1; i > 0; i--) {
        maxt = 0;
        maxdl = 0;
        maxdr = 0;

        maxt = pomar[i - 1][c];

        if (c != 0) {
            maxdl = pomar[i - 1][c - 1];
        }
        if (c != numMacieiras - 1) {
            maxdr = pomar[i - 1][c + 1];
        }

        if (maxt >= maxdl && maxt >= maxdr) {
        }
        else if (maxdl >= maxt && maxdl >= maxdr) {
            c = c - 1;

        }
        else if (maxdr >= maxt && maxdr >= maxdl) {
            c = c + 1;
        }
        ind.push_back(c);


    }
    return ind;

}

void Colheita::print() {
    Colheitadeira c = caminho();
    cout << c.maxi << endl;

    for (int i = numFileiras - 1; i >= 0; i--) {
        cout << (c.indices[i]) << " ";
    }
}

