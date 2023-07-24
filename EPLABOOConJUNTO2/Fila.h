#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila {
public:
    Fila(int tamanho);
    ~Fila();
    bool enqueue(Datagrama* d);
    Datagrama* dequeue();
    bool isEmpty();
    int getSize();
    void imprimir();

private:
    int tamanho, tamanhoFila;
    Datagrama** vetorFila;
};

#endif // FILA_H
