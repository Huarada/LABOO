#include <iostream>
#include <string>
using namespace std;
#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, string dado) {
    this->origem = origem;
    this->destino = destino;
    this->dado = dado;
}

Datagrama::~Datagrama() {
    cout << "Datagrama deletado" << endl;
}

int Datagrama::getOrigem() {
    return origem;
}

int Datagrama::getDestino() {
    return destino;
}

string Datagrama::getDado() {
    return dado;
}

void Datagrama::imprimir() {
}
