#include <iostream>
#include <string>
using namespace std;

#include "Roteador.h"

Roteador::Roteador(int endereco) {
    this->endereco = endereco;
    tabela = new TabelaDeRepasse(TAMANHO);
    fila = new Fila(TAMANHO);
}

Roteador::~Roteador() {
    delete[] tabela;
    delete[] fila;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso) {
    return tabela -> mapear( endereco,  adjacente, atraso);
}

void Roteador::setPadrao(Roteador* padrao, int atraso) {
    tabela ->setPadrao(padrao, atraso);
}

int Roteador::getEndereco() {
    return endereco;
}

void Roteador::receber(Datagrama* d) {
    fila->enqueue(d);
    if (!fila->enqueue(d)) {
        cout << "\t Fila em " << endereco << " estourou" << endl;
    }
}
