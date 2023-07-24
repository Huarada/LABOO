#ifndef EVENTO_H
#define EVENTO_H


#include "roteador.h"
#include "datagrama.h"

class Roteador;


class Evento {


public:
   Evento(int instante, Roteador* destino, Datagrama* d);


   ~Evento();

   int getInstante();

   Roteador* getDestino();

   Datagrama* getDatagrama();

   void imprimir();


private:

  Datagrama* recebido;

  Roteador* destino;

  int atraso_propagado;


};


#endif  // EVENTO_H
