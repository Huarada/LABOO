
#include "Evento.h"
#include <string>
#include "No.h"
#include <iostream>
using namespace std;
Evento::Evento(int instante,No* destino, Datagrama* d) : instante(instante),destino(destino),d(d){



}

Evento::~Evento(){
}


int Evento::getInstante(){

  return instante;
}

No* Evento::getDestino(){

return destino;
}

Datagrama* Evento::getDatagrama(){

  return d;
}

void Evento::imprimir(){

cout<< "Evento de destino   com informacao "<< d->getSegmento()->getDado() << " ocorreu no instante "<< instante <<endl;

}

