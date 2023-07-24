#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, Segmento* dado)
    : origem(origem), destino(destino), dado(dado) {}

Datagrama::~Datagrama() {
    delete dado;
    // cout << "Datagrama destruido" << endl;
}

int Datagrama::getOrigem() {
    return origem;
}

int Datagrama::getDestino() {
    return destino;
}

Segmento* Datagrama::getSegmento() {
    return dado;
}

void Datagrama::imprimir() {
    cout << "Origem: " << origem << ":" << dado->getPortaDeOrigem();
    cout << ", Destino: " << destino << ":" << dado->getPortaDeDestino();
    cout << ", " << dado->getDado();
}
