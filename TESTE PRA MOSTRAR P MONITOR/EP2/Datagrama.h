#ifndef DATAGRAMA_H
#define DATAGRAMA_H

#include "Segmento.h"

class Datagrama {
public:
    Datagrama(int origem, int destino, Segmento* dado);
    virtual ~Datagrama();

    virtual int getOrigem();
    virtual int getDestino();
    virtual Segmento* getSegmento();

    virtual void imprimir();

private:
    int origem, destino;
    Segmento* dado;

};

#endif // DATAGRAMA_H
