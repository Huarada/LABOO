#include <string>
#include "fila.h"
#include <iostream>
#include "datagrama.h"
using namespace std;

Fila::Fila(int tamanho){
this -> tamanho = tamanho;
this->vetor = new Datagrama*[tamanho];

cont = 0;

inicio = 0;
}


Fila::~Fila(){
cout << "Fila destruida" << endl;


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


bool Fila::enqueue(Datagrama* d){
if (cont == tamanho){

    return false;
}
else{
vetor[fim] = d;
cont = cont + 1;

if (fim == tamanho){
    fim = 0;

    return true;
}
else { fim = fim + 1;

}

return true;
}
}



Datagrama* Fila::dequeue(){
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

  }

}
}
