#include "FilaComPrioridade.h"
#include "fila.h"
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
FilaComPrioridade::FilaComPrioridade(int tamanho): Fila(tamanho){

}

FilaComPrioridade::~FilaComPrioridade(){
  cout << "Fila com prioridade destruida" << endl;

for (int i = 0; i < cont; i++){
  delete vetor[i];
}
delete[] vetor;
}

void FilaComPrioridade::enqueue(Datagrama* d,bool prioritario){
 if(cont >= tamanho){
    throw new overflow_error("enqueue impossivel,Overflow!"); // PROTEGER CODIGO
 }
if(prioritario == false){
    Fila::enqueue(d);  // INSERIR TERMO NAO PRIORITARIO
}
else{
  Datagrama* prioridadetemp = vetor[fim-1] ;


  for(int j = apoio ; j< fim ; j++){        //SHIFT RIGHT DOS TERMOS NÃO PRIORITARIOS
    vetor[j+1] = vetor[j];
  }
  vetor[apoio] = d;               //INSERIR TERMO PRIORITARIO
  Fila::enqueue(prioridadetemp);  //INSERIR O NAO PRIORITARIO APAGADO PELO SHIFT
  apoio++;                        // APOIO MOSTRA A DIVISAO ENTRE TERMOS PRIORITARIOS E NAO PRIORITARIOS

}
}
