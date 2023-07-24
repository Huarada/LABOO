#include <iostream>
#include "datagrama.h"
#include <string>
#include "fila.h"
using namespace std;







int main()
{ Datagrama * roteador = new Datagrama(3, 2, "pinto");
  roteador -> imprimir();

  Datagrama * roteador2 = new Datagrama ( 40,50, "caiu a net");
  roteador2 -> imprimir();
  Datagrama * roteador3 = new Datagrama ( 40,7, "reprovei kek");
  roteador3 -> imprimir();
  Datagrama * roteador4 = new Datagrama ( 7,40, "poggers");
  roteador4 -> imprimir();


  Fila *falido = new Fila(4);

  falido -> enqueue(roteador);
  falido -> enqueue(roteador2);
  falido -> enqueue(roteador3);
  falido -> enqueue (roteador4);
 falido -> dequeue();

  falido -> imprimir();


  delete roteador;
  delete roteador2;
  delete roteador3;
  delete roteador4;
  return 0;



}
