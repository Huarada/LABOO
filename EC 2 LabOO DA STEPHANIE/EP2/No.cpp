#include "No.h"

No::No(int endereco) : fila(new Fila(TAMANHO_FILA)), endereco(endereco) {}

No::No(int endereco, Fila* fila) : fila(fila), endereco(endereco) {}

No::~No() {
    delete fila;
}

int No::getEndereco() {
    return endereco;
}

/*
Evento* No::processar(int instante) {

}
*/

void No::receber(Datagrama* d) {
    if (fila->getSize() >= TAMANHO_FILA) {
        delete d;
        cout << "\tFila em " << endereco << " estourou" << endl;
    }
    else fila->enqueue(d);
}

void No::imprimir() {

}
