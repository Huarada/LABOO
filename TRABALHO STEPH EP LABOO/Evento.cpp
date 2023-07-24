#include "Evento.h"

Evento::Evento(int instante, Roteador* destino, Datagrama* d) {
    this->instante = instante;
    this->destino = destino;
    this->d = d;
}

Evento::~Evento() {
}

int Evento::getInstante() {
    return instante;
}

Roteador* Evento::getDestino() {
    return destino;
}

Datagrama* Evento::getDatagrama() {
    return d;
}

void Evento::imprimir() {
}
