#include "Evento.h"

Evento::Evento(int instante, No* destino, Datagrama* d)
    : instante(instante), destino(destino), d(d) {}

Evento::~Evento() {
 cout << "Evento destruido" << endl;
}

int Evento::getInstante() {
    return instante;
}

No* Evento::getDestino() {
    return destino;
}

Datagrama* Evento::getDatagrama() {
    return d;
}

void Evento::imprimir() {
}

