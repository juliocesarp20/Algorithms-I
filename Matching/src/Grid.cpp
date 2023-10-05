#include "Grid.hpp"
#include "LojaClientes.hpp"
#include <queue>
Grid::Grid(int N, int M){
    this->N=N;
    this->M=M;
    deque<deque<int>> vec(M, deque<int> (N, 0));
    grid = vec;
}
void Grid::setN(int N){
    this->N=N;
}
void Grid::setM(int M){
    this->M=M;
}
void Grid::alocarClientesLoja(){
    for(std::size_t i = 0; i < clientes.size(); i++){
      for(std::size_t j = 0; j < lojaClientes.size(); j++){
           clientes.at(i).addLoja(lojaClientes.at(j).getLoja());
       }
    }
}


void Grid::addCliente(Cliente c){
    clientes.push_back(c);
}

void Grid::addLoja(Loja l){
    LojaClientes lc = LojaClientes(l);
    lojaClientes.push_back(lc);
}


int Grid::getN(){
    return N;
}
int Grid::getM(){
    return M;
}

deque<Cliente> Grid::getClientes(){
    return this->clientes;
}

deque<LojaClientes> Grid::getLojaClientes(){
    return this->lojaClientes;
}
int Grid::estoque(){
    int soma=0;
    for(std::size_t i=0;i<lojaClientes.size();i++){
        soma+=lojaClientes.at(i).getLoja().getTotal();
    }
    return soma;
}

int Grid::preferencial(Cliente c,int cl) {
    double ticketc = c.getTicket();
    //Verifica se o cliente tem preferencia em relacao ao cliente alocado na loja com menor preferencia
    double ticketp = lojaClientes.at(cl).getClientes()[0].getTicket();
            if (ticketc > ticketp) {  
                //Se o ticket for maior, retorna o cliente que deve ser substituido
                return lojaClientes.at(cl).getClientes()[0].getId();
            }
            //Se os tickets forem iguais, retorna o que tem o menor ID
            else if (ticketc==ticketp && c.getId() < lojaClientes.at(cl).getClientes()[0].getId()) {
                return lojaClientes.at(cl).getClientes()[0].getId();
                }
    return -1;
}


void Grid::match(){
    alocarClientesLoja();
    Cliente c;
    int m = clientes.size();
    int n = lojaClientes.size();
    deque<Cliente> naopropostos(clientes);
    int k = 0;
    //Faz a alocacao ate que todos os clientes tenham buscado pelo menos uma proposta
    while(naopropostos.size() != 0){
            k = naopropostos.front().getId();
            if (clientes[k].getLojas().size() > 0) {
                int cl = clientes[k].getLojas()[0].getId();
                int estoquel = lojaClientes.at(cl).getLoja().getEstoque();
                //Se a loja tiver estoque, faz a alocacao na loja
                if (estoquel > 0) {
                    lojaClientes.at(cl).addCliente(clientes[k]);
                    int estoqueF = lojaClientes.at(cl).getLoja().getEstoque() - 1;
                    lojaClientes.at(cl).changeEstoque(estoqueF);
                    naopropostos.pop_front();
                    clientes[k].deleteLoja();
                    
                }
                else {
                    //Se nao verifica se o cliente tem preferencia para substituir alguem na loja
                    int preferencia = preferencial(clientes[k],cl);
                    if (preferencia != -1) {
                        //Se tiver preferencia, o cliente com menor preferencia eh removido da loja e o cliente novo eh adicionado
                        lojaClientes.at(cl).removeCliente();
                        lojaClientes.at(cl).addCliente(clientes[k]);
                        int np = naopropostos.size();
                        for (int i = 0; i < np; i++) {
                            if (naopropostos[i].getId() == clientes[k].getId()) {
                                naopropostos.erase(naopropostos.begin() + i);
                                break;
                            }
                        }
                        for (int i = 0; i < m; i++) {
                            if (clientes[i].getId() == preferencia) {
                                naopropostos.push_front(clientes[i]);
                                break;
                            }
                        }
                    }
                    else {
                        clientes[k].deleteLoja();
                    }
                }
            }
            else {
                naopropostos.erase(naopropostos.begin());
            }
    }
    //Ordena os clientes na loja pelo maior ticket
    n = lojaClientes.size();
       for (int i = 0; i < n; i++) {
        lojaClientes.at(i).sort();
    }
}

void Grid::print(){
    //Imprime os clientes alocados
    int n = lojaClientes.size();
    for (int i = 0; i < n; i++) {
        cout << i << endl;
        int s = lojaClientes.at(i).getClientes().size();
        for(int j=0;j<s;j++){
                if(j!=s-1){
                cout << lojaClientes.at(i).getClientes()[j].getId() << " ";
                }else{
                cout << lojaClientes.at(i).getClientes()[j].getId();
                }
        }
        cout << endl;
    }
}

