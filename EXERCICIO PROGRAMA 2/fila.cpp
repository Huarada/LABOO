#include <string>
#include "fila.h"
#include <iostream>
#include "datagrama.h"
#include <stdexcept>

using namespace std;

Fila::Fila(int tamanho){
if (tamanho <= 0){
    throw new invalid_argument("Tamanho invalido!");
}

this -> tamanho = tamanho;
this->vetor = new Datagrama*[tamanho];

cont = 0;

inicio = 0;
}


Fila::~Fila(){
cout << "Fila destruida" << endl;

for (int i = 0; i < cont; i++){
  delete vetor[i];
}
delete[] vetor;

}

int Fila::getSize(){

return cont;

}



bool Fila::isEmpty(){
  if (fim == inicio ) {
    return true;
    }
  return false;


}


void Fila::enqueue(Datagrama* d){
if (cont >= tamanho){

    throw new overflow_error("Erro de overflow");
}
else{
vetor[fim] = d;
cont = cont + 1;

if (fim == tamanho){
    fim = 0;


}
else { fim = fim + 1;}


}
}



Datagrama* Fila::dequeue(){
if (cont <= 0){
 throw new underflow_error("Erro de Underflow");
}
retira = vetor[inicio];

if (inicio == tamanho) {

    inicio = 0;

}
else {inicio = inicio +1;}


cont = cont -1;
return retira;


}






void Fila::imprimir() {


cout << "Fila de tamanho maximo " << tamanho << " com " << getSize() << " termos eh vazia  " <<isEmpty()<< endl;

    if(inicio >= fim ){


    for (int i = inicio; i < tamanho; i++) {
        cout << "\t";

        vetor[i]->imprimir();


    for (int i = 0; i < fim; i++) {
        cout << "\t";

        vetor[i]->imprimir();
}
}
}

  else {
        for (int i = inicio; i < fim; i++) {
        cout << "\t";

        vetor[i]->imprimir();
}}}







