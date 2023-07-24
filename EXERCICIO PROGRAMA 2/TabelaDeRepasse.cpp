#include "TabelaDeRepasse.h"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho){
if(tamanho == 0){

   throw new invalid_argument("tamanho da tabela eh 0!");
}
quantidadeDeAdjacentes = 0;
padrao = NULL;
atraso_padrao = 0;

adjacentes = new No*[tamanho];
enderecos = new int [tamanho];
atrasos = new int [tamanho];


}

TabelaDeRepasse::~TabelaDeRepasse(){

delete[] adjacentes;
delete[] enderecos;
delete[] atrasos;
}

void TabelaDeRepasse::mapear(int endereco,No* adjacente, int atraso){
 if(quantidadeDeAdjacentes >= tamanho) throw new overflow_error("mapeamento com overflow");
 for(int i = 0; i< quantidadeDeAdjacentes; i++){
    if(enderecos[i] == endereco) throw new invalid_argument(" Endereco ja foi mapeado!");
 }
   enderecos[quantidadeDeAdjacentes] = endereco;
   adjacentes[quantidadeDeAdjacentes] = adjacente;
   atrasos[quantidadeDeAdjacentes] = atraso;

   quantidadeDeAdjacentes ++;
}

No** TabelaDeRepasse::getAdjacentes(){

return adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){

return quantidadeDeAdjacentes;
}

void TabelaDeRepasse::setPadrao(No* padrao, int atraso) {
    this->padrao = padrao;
    atraso_padrao = atraso;
}

No* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso){

for(int i = 0; i < quantidadeDeAdjacentes; i++){
    if(enderecos[i] == endereco){
        atraso = atrasos[i];
        return adjacentes[i];
    }}

if(padrao == NULL){
    atraso = 0;
    return NULL;
}

atraso = atraso_padrao;
return padrao;
}


void TabelaDeRepasse::imprimir(){
int z =0;
cout<<" Fila de Adjactentes : " ;
cout<< getQuantidadeDeAdjacentes()<<endl;
cout<< "Lista de adjacentes :"<<endl;
while (z< getQuantidadeDeAdjacentes()){
   cout<< adjacentes[z] ->getEndereco()<<"  ";
    z++;

}
}





