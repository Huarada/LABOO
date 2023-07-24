

#ifndef FILA_H
#define FILA_H



#include "datagrama.h"


class Fila {


private:
    int tamanho;
    int fim = 0;
    int inicio = 0;
    int cont = 0;

    Datagrama **vetor;
    Datagrama *retira;



public:
    Fila(int tamanho);
    ~Fila();
    bool enqueue(Datagrama* d);
    Datagrama* dequeue();
    bool isEmpty();
    int getSize();
    void imprimir();



};

#endif

