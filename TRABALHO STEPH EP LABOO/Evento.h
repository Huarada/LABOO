#ifndef EVENTO_H
#define EVENTO_H

#include "Roteador.h"
#include "Datagrama.h"

class Roteador;

class Evento {
public:
    Evento(int instante, Roteador* destino, Datagrama* d);
    ~Evento();
    int getInstante();
    Roteador* getDestino();
    Datagrama* getDatagrama();
    void imprimir();

protected:

private:
    int instante;
    Roteador* destino;
    Datagrama* d;
};

#endif // EVENTO_H
