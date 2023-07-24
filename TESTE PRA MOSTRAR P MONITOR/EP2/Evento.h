#ifndef EVENTO_H
#define EVENTO_H

#include "No.h"
#include "Datagrama.h"

class No;

class Evento {
public:
    Evento(int instante, No* destino, Datagrama* d);
    virtual ~Evento();

    virtual int getInstante();
    virtual No* getDestino();
    virtual Datagrama* getDatagrama();

    virtual void imprimir();

protected:

private:
    int instante;
    No* destino;
    Datagrama* d;
};

#endif // EVENTO_H
