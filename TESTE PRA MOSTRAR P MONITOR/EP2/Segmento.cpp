#include "Segmento.h"

Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado)
    : portaDeOrigem(portaDeOrigem), portaDeDestino(portaDeDestino), dado(dado) {}

Segmento::~Segmento() {
    // cout << "Segmento destruido" << endl;
}

int Segmento::getPortaDeOrigem() {
    return portaDeOrigem;
}

int Segmento::getPortaDeDestino() {
    return portaDeDestino;
}

string Segmento::getDado() {
    return dado;
}

void Segmento::imprimir() {
    cout << "Segmento " << dado << " de origem " << portaDeOrigem << " e destino " << portaDeDestino << endl;
}
