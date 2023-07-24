#include "roteador.h"
#include "tabeladerepasse.h"
#include <string>
#include <iostream>
using namespace std;

Roteador::Roteador(int endereco){

endereco_rot = endereco;

tabela_rot = new TabelaDeRepasse(TAMANHO);
fila_rot = new Fila(TAMANHO);


};



bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso){



 return tabela_rot -> mapear(endereco,adjacente,atraso);



};



void Roteador::setPadrao(Roteador* padrao, int atraso){

  tabela_rot->setPadrao(padrao,atraso);


}

int Roteador::getEndereco(){

return endereco_rot;

};


void Roteador::receber(Datagrama* d){

if (fila_rot ->getSize() == TAMANHO){
    cout << "\t Fila em "<<getEndereco()<< "estourou"<< endl;


}
else{

    fila_rot->enqueue(d);



}


};





Evento* Roteador::processar(int instante){

if(fila_rot->isEmpty() == 1){

    return NULL;


}
else {
   cout<<"roteador "<<getEndereco()<<endl;
  memoria_rot = fila_rot -> dequeue();



  if (memoria_rot->getDestino() == getEndereco()){

      delete memoria_rot;
      return NULL;
}

// item 2 de processar


else if(tabela_rot->getProximoSalto(memoria_rot->getDestino(),atraso_evento) == NULL){
    cout <<"\tSem proximo: "<<" origem:"<<memoria_rot ->getOrigem()<<", destino: "<<memoria_rot->getDestino()<<", "<<memoria_rot ->getDado()<<endl;
    return NULL; }


else {
      // print caso o datagrama seja repassado
      cout<<"\tRepassado para "<< tabela_rot->getProximoSalto(memoria_rot->getDestino(),atraso_evento) ->getEndereco() <<"(instante "<< instante<<"): origem:"<<memoria_rot ->getOrigem()<<", destino: "<<memoria_rot->getDestino()<<", "<<memoria_rot ->getDado()<<endl;
      atraso_evento = instante;

       tabela_rot->getProximoSalto(memoria_rot ->getDestino(),instante);

       atraso_evento = atraso_evento + instante;

       evento_rot = new Evento(atraso_evento,tabela_rot -> getProximoSalto(memoria_rot ->getDestino(),instante),memoria_rot);

       return evento_rot;
}
}
};

