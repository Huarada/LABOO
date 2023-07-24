
#include "Segmento.h"
#include <string>
#include <iostream>
using namespace std;

Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado) :
portaDeOrigem(portaDeOrigem), portaDeDestino(portaDeDestino), dado(dado)
{
}
 Segmento::~Segmento(){


 cout << "parametros deletados" <<endl;
}

int Segmento::getPortaDeDestino(){

return portaDeDestino;
}

int Segmento::getPortaDeOrigem(){

return portaDeOrigem;
}

string Segmento::getDado(){
 return dado;
}

void Segmento::imprimir(){

cout << "Dado: "<< dado<< ", Porta De Destino : " << portaDeDestino << ", Porta De Origem: " << portaDeOrigem << endl;
}

