#include "Segmento.h"
#include <string>
#ifndef DATAGRAMA_H

#define DATAGRAMA_H

class Datagrama{

public :
Datagrama(int origem, int destino, Segmento* dado);

virtual ~Datagrama();

virtual int getOrigem();
virtual int getDestino();
virtual Segmento* getSegmento();

virtual void imprimir();

private:
int origem;
int destino;
Segmento* dado;
};

#endif // DATAGRAMA_H
