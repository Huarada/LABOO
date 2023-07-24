#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila {
public:
    Fila(int tamanho);
    virtual ~Fila();

    virtual void enqueue(Datagrama* d);
    virtual Datagrama* dequeue();
    virtual bool isEmpty();
    virtual int getSize();

    virtual void imprimir();

protected:
    int tamanho, quantidade;
    Datagrama** filaAtual;

private:

};

#endif // FILA_H
