 #include <iostream>
 #include <string>
 #include "datagrama.h"
 using namespace std;










 Datagrama::Datagrama( int origem, int destino, string dado){

 this -> origem = origem;
 this -> destino = destino;
 this -> dado = dado;





 }



Datagrama::~Datagrama(){

cout << "Datagrama foi destruido" << endl;


}



int Datagrama::getOrigem(){

return origem;

}



int Datagrama::getDestino(){

   return destino;
}



string Datagrama::getDado(){

  return dado;

}



void Datagrama::imprimir(){

cout<< "no de origem "<< getOrigem() << " enviou " << getDado() << " para " << getDestino() << endl;

}
