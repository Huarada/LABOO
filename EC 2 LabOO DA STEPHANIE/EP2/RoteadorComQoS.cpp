#include "RoteadorComQoS.h"

RoteadorComQoS::RoteadorComQoS(int endereco)
    : Roteador(endereco, filaPrioridade) {
    filaPrioridade = new FilaComPrioridade(TAMANHO_FILA);
    prioritarios = new vector<int>();
}

RoteadorComQoS::~RoteadorComQoS() {
    delete prioritarios;
}

void RoteadorComQoS::priorizar(int destino) {
    prioritarios->push_back(destino);
}

vector<int>* RoteadorComQoS::getDestinosPriorizados() {
    return prioritarios;
}

void RoteadorComQoS::receber(Datagrama* d) { // REDEFINICAO DO METODO
    if (filaPrioridade->getSize() >= TAMANHO_FILA) {
        delete d;
        cout << "\tFila em " << endereco << " estourou" << endl;
    }
    else {
        for (unsigned int i = 0; i < prioritarios->size(); i++) {
            if (d->getDestino() == prioritarios->at(i)) {
                filaPrioridade->enqueue(d, true);
            }
            else {
                filaPrioridade->enqueue(d, false);
            }
        }
    }
}
