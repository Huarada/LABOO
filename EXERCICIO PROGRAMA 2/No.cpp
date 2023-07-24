
#include "No.h"
#include <iostream>
using namespace std;

No::No(int endereco,Fila* fila): endereco(endereco),fila(fila){
tamanhoMaxFila = fila->getSize();
}

No::No(int endereco) : endereco(endereco){

 fila = new Fila(TAMANHO_FILA);
 tamanhoMaxFila = TAMANHO_FILA;

}

 No::~ No (){

delete fila;

}
int No::getEndereco(){
 return endereco;
}



void No::receber(Datagrama* d){
if (fila->getSize() >= tamanhoMaxFila ){
    cout <<"Fila em endereco "<<getEndereco()<<" estourou"<<endl;
}
else{
fila->enqueue(d);
}

}

void No::imprimir(){

cout<< "No de endereco "<< getEndereco()<< " de Fila ";
 fila->imprimir();
}

Evento* No::processar(int instante){ // ESTAH COMO DUMMIE

return NULL;

}


