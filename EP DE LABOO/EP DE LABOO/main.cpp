#include <iostream>
#include "datagrama.h"
#include <string>
#include "fila.h"
#include "roteador.h"
#include "tabeladerepasse.h"
#include "evento.h"
using namespace std;







int main()
{ /*

  Datagrama * roteador = new Datagrama(3, 2, "pinto");
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
*/
//TESTE DA TABELAREPASSE
Roteador* rot1 = new Roteador(1);
Roteador* rot2 = new Roteador(2);
Roteador* rot3 = new Roteador(3);
Roteador* rot4 =new Roteador(4);

Roteador* rot5 =new Roteador(6);
TabelaDeRepasse* tab = new TabelaDeRepasse(4);
tab ->mapear(1,rot1,2);
tab ->mapear(2,rot2,2);
tab ->mapear(3,rot2,2);
tab->setPadrao(rot5,3);
tab -> imprimir();





Datagrama* mensagem1 = new Datagrama(1,6,"oi");
Datagrama* mensagem2 = new Datagrama(4,2,"alo");
Evento* eventao = new Evento(3,rot5,mensagem1);
Roteador* dorgas = new Roteador(2);
dorgas ->receber(mensagem1);
dorgas ->receber(mensagem2);

dorgas ->mapear(6,rot3,3);
eventao = dorgas ->processar(2);
cout<<"compilou "<<endl;

return 0;


}
