#include "LojaClientes.hpp"
LojaClientes::LojaClientes(deque<Cliente> c, Loja l){
this->clientes = c;
this->loja = l;
c.resize(l.getTotal());
}

LojaClientes::LojaClientes( Loja l){
this->loja = l;
}

void LojaClientes::setLoja(Loja l){

    this->loja = l;
}
Loja LojaClientes::getLoja(){
    return this->loja;
}

deque<int> LojaClientes::getIds(){
    return ids;
}

deque<Cliente> LojaClientes::getClientes(){
    return clientes;
}


void LojaClientes::addCliente(Cliente c){
    auto it = clientes.begin();
    bool insert = false;
    for (std::size_t i = 0; i < clientes.size(); i++) {
        if (c.getTicket() < clientes.at(i).getTicket()) {
            it = clientes.insert(clientes.begin() + i, c);

            insert = true;
            break;
        }
        else if ((c.getTicket() == clientes.at(i).getTicket())) {
            int aux = -1;
            for (std::size_t j = i; j < clientes.size(); j++) {
                if (c.getId() > clientes.at(j).getId() && c.getTicket()==clientes.at(j).getTicket()) {
                    aux = j;
                }
            }
            if (aux != -1) {
                it = clientes.insert(clientes.begin() + aux, c);
                insert = true;
                break;
            }
        }

    }
    if (!insert) {
        clientes.push_back(c);
    }
}

void LojaClientes::removeCliente() {
    clientes.pop_front();
}
void LojaClientes::changeEstoque(int estoque){
    loja.setEstoque(estoque);
}

void LojaClientes::sort() {
    std::sort(clientes.begin(), clientes.end(), [](Cliente& a, Cliente& b) {
        return a.getId() < b.getId();
        });
    std::stable_sort(clientes.begin(), clientes.end(), [](Cliente c1, Cliente c2)
        {
            return c1.getTicket() > c2.getTicket();
        });
}