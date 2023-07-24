
#include "tabeladerepasse.h"
#include <string>
#include <iostream>
using namespace  std ;



TabelaDeRepasse::TabelaDeRepasse(int tamanho){
this -> quantidade = 0;
this ->enderecos = new int [tamanho];

adjacente = new Roteador*[tamanho] ;

this -> atrasos = new int [tamanho];

this->  padrao = NULL;
this -> atraso_padrao = 0;




};


bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso){
if (quantidade == tamanho) { return false;} // VETOR CHEIO

for (int i = 0; i < quantidade; i++) {
   if (enderecos[i] == endereco) return false; // JA TEM ENDERECO NA TABELA
    }


this -> enderecos[quantidade] = endereco;
this -> adjacente[quantidade] = adjacente;
 atrasos[quantidade] = atraso;
quantidade = quantidade + 1;

};




Roteador** TabelaDeRepasse::getAdjacentes(){


return adjacente;

};


int TabelaDeRepasse::getQuantidadeDeAdjacentes(){


return quantidade;




};



void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso){


this -> padrao = padrao;
atraso_padrao = atraso;





};


Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){

for ( int j = 0; j < quantidade; j++ ){

    if (enderecos[j] == endereco) {
        atraso = atrasos[j];
        return adjacente[j];
    }



}
atraso = atraso_padrao;
return padrao;




};



void TabelaDeRepasse::imprimir(){

cout<< "Tabela de tamanho "<< getQuantidadeDeAdjacentes() <<" com roteador padrao "<<padrao->getEndereco()<<" e atraso padrao "<<atraso_padrao<<endl;
for (int i = 0; i < quantidade; i++){

    cout<<"endereco = "<< enderecos[i]<<",  ";


}
cout<<"" <<endl;
for (int i = 0; i < quantidade; i++){

    cout<<"roteador = "<< adjacente[i] ->getEndereco()<<",  ";

}
cout <<""<<endl;


for (int i = 0; i < quantidade; i++){

cout<<"atraso = "<< atrasos[i]<<",  ";


}
}


