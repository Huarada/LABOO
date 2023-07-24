#include "Segmento.h"
#include "Datagrama.h"
#include <iostream>
using namespace std;

Datagrama::Datagrama(int origem,int destino, Segmento* dado) : origem (origem), destino(destino), dado(dado){
}

Datagrama::~Datagrama(){
    delete dado;
}

int Datagrama::getDestino(){

return destino;
}

int Datagrama::getOrigem(){

return origem;
}

Segmento* Datagrama::getSegmento(){

return dado;
}

void Datagrama::imprimir(){

cout << " Datagrama de origem " << origem<< " e destino " <<destino <<" transmitindo dado: "<< getSegmento()->getDado() << endl;
}


