#include "evento.h"


Evento::Evento(int instante, Roteador* destino, Datagrama* d){

atraso_propagado = instante;

this -> destino = destino;

recebido = d;

};


int Evento::getInstante(){

  return atraso_propagado;


};



Roteador* Evento::getDestino(){

  return destino;

};


Datagrama* Evento::getDatagrama(){

return recebido;



};
